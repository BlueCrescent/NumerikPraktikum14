/*
 * main_s4_07.cpp
 *
 *  Created on: Jun 19, 2014
 *      Author: boris
 */

#include <iostream>

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
void runTest(const double startSigma = computeDefaultSigma<isCall>(S0, r, T, K, historicalSigma, maxIterations)) {
//  const double startSigma = 10; // computeDefaultSigma<isCall>(S0, r, T, K, historicalSigma, maxIterations);

//  std::cout << "Running with sigma = " << startSigma << ". The default sigma would be "
//            << computeDefaultSigma<isCall>(S0, r, T, K, historicalSigma, maxIterations) << "." << std::endl;

  std::cout << "Running with historical sigma = " << historicalSigma
            << " and start sigma = " <<  startSigma << "." << std::endl;
  try {
    const double impliedVolatility = executeNewtonRaphsonAlgo<isCall>(S0, r, T, K, historicalSigma, startSigma, maxIterations);
    std::cout << "The implied volatility is " << impliedVolatility << "." << std::endl;
    results[idx++] = impliedVolatility;
  } catch (NoConvergenceError & error) {
    std::cout << "No convergence! Last sigma was " << error.getLastSigma() << "." << std::endl;
    results[idx++] = error.getLastSigma();
  }
}

template<bool isCall>
void printResults();

void main_s4_07() {
  for (double histSigma: histSigmas) {
    historicalSigma = histSigma;
    runTest<CALL>();
//    runTest<PUT>();
    for (double sigma: sigmas) {
      runTest<CALL>(sigma);
//      runTest<PUT>(sigma);
    }
  }

//  for (double result: results) {
//    std::cout << result << " ";
//  }
//  std::cout << std::endl;
  printResults<CALL>();
//  std::ofstream out;
//  out.open("data_s4_07");
//  // do sth with out
//  out.close();
}

#include <cstdio>

template<bool isCall>
void printResults() {
  const double defaultSigma = computeDefaultSigma<isCall>(S0, r, T, K, historicalSigma, maxIterations);
  printf("           %10.7lf %10.7lf %10.7lf %10.7lf %10.7lf \n", defaultSigma, sigmas[0], sigmas[1], sigmas[2], sigmas[3]);
  for (int i = 0; i < 4; ++i) {
    printf("%10.7lf ", histSigmas[i]);
    for (int j = 0; j < 5; ++j) {
      printf("%10.7lf ", results[i * 4 + j]);
    }
    printf("\n");
  }
}
