/*
 * main_s4_07.cpp
 *
 *  Created on: Jun 19, 2014
 *      Author: boris
 */

#include <fstream>
#include <iomanip>

#include "NewtonRaphson.h"

namespace {
  const double S0 = 10.;
  const double r = 0.05;
  const double T = 1.;
  const double K = 10.;
  const unsigned int maxIterations = 1000;

  double historicalSigma = -1.;

  const double sigmas[] = {0.01, 1, 10, 0.1};
  const double histSigmas[] = {0.01, 1, 9, 0.001};

  double results[4 * 5];
  int idx = 0;
}

template<bool isCall>
void runOneNewtonRaphsonTest(const double startSigma = computeDefaultSigma<isCall>(S0, r, T, K, historicalSigma, maxIterations)) {

//  std::cout << "Running with historical sigma = " << historicalSigma
//            << " and start sigma = " <<  startSigma << "." << std::endl;
  try {
    const double impliedVolatility = executeNewtonRaphsonAlgo<isCall>(S0, r, T, K, historicalSigma, startSigma, maxIterations);
//    std::cout << "The implied volatility is " << impliedVolatility << "." << std::endl;
    results[idx++] = impliedVolatility;
  } catch (NoConvergenceError & error) {
//    std::cout << "No convergence! Last sigma was " << error.getLastSigma() << "." << std::endl;
    results[idx++] = error.getLastSigma();
  }
}

template<bool isCall>
void runNewtonRaphsonTest(const char * filename);

void main_s4_07() {
  runNewtonRaphsonTest<CALL>("data_s4_07_call");

  runNewtonRaphsonTest<PUT>("data_s4_07_put");
}

template<bool isCall>
void printResults(std::ostream & out) {
  const double defaultSigma = computeDefaultSigma<isCall>(S0, r, T, K, historicalSigma, maxIterations);
  out << (isCall ? "Call" : "Put") << " values with default sigma " << defaultSigma << ":" << std::endl;

  out << std::setprecision(7) << std::setfill(' ') << std::fixed
      << "           &" << std::setw(10) << defaultSigma << " &" << std::setw(10) << sigmas[0]
      << " &" << std::setw(10) << sigmas[1] << " &" << std::setw(10) << sigmas[2] << " &" << std::setw(10) << sigmas[3]
      << std::endl;

  for (int i = 0; i < 4; ++i) {
    out << std::setw(10) << histSigmas[i] << " ";
    for (int j = 0; j < 5; ++j)
      out << "&" << std::setw(10) << results[i * 5 + j] << " ";
    out << std::endl;
  }
}

template<bool isCall>
void runNewtonRaphsonTest(const char * filename) {
  std::ofstream out;
  out.open(filename);

  for (double histSigma : histSigmas) {
    historicalSigma = histSigma;
    runOneNewtonRaphsonTest<isCall>();
    for (double sigma : sigmas) {
      runOneNewtonRaphsonTest<isCall>(sigma);
    }
  }

  printResults<isCall>(out);
  out.close();
}
