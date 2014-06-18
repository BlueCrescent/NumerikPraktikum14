/*
 * main.cpp
 *
 *  Created on: 08.05.2014
 *      Author: boris
 */

#include "geometricBM.h"
#include "Cpp11NormalDice.h"
#include "asian_fair_prices.h"

#include "NormalCDF.h"

#include <fstream>
#include <iomanip>
#include <cmath>

void simulateGeometricAverage(int M, const char * filename);

void main_s3_03() {
  const int M1 = 10, M2 = 200;

  simulateGeometricAverage(M1, "data_s3_03_M10");
  simulateGeometricAverage(M2, "data_s3_03_M200");
}

inline double exactExpectationForCallOptionValue2() {
  const double S0 = 10., mu = 0.1, sigma = 0.25, T = 1., K = 10.;
  if (K == 0.)
    return S0 * exp(mu * T);
  const double X = 1. / (sigma * sqrt(T)) * (log(K / S0) - (mu - sigma * sigma / 2) * T);
  const double expectation = S0 * exp(mu * T) * NormalCDF(sigma * sqrt(T) - X) - K * NormalCDF(- X);
  return expectation;
}

void simulateAndPrintRelativeError(int M, std::ostream& outStream) {
  const double start_value = 10, r = 0.1, sigma = 0.25, strike = 10, T = 1., delta_t = T / M;
  const geometricBMParameter Parameters {start_value, r, sigma, delta_t};
  Cpp11NormalDice Dice;

  const double expectedPayoff1 = calc_discrete_geometric_fairP(start_value, r, sigma, strike, T, M);
  const double discountFactor = exp(- r * T);

  double compVal = start_value*exp(r) - strike;

  double sum = 0;
  for (int i = 1; i < 100000; i++) {
//  int i = 1;
    geometricBM Path(Parameters, Dice);
    const std::vector<double> values = Path.compute_path_values(M);
    sum += evaluate_discr_geometric_payoff(values, strike);
    if ((i + 1) % 1000 == 0) {
      outStream << i << " " << fabs(discountFactor * sum / i - expectedPayoff1) / expectedPayoff1 << std::endl;
      outStream << i << " " << discountFactor * sum / i << " " << " " << expectedPayoff1 <<" "<< std::endl;//<< discountFactor * exactExpectationForCallOptionValue2() << std::endl;
    }
  }

}

void simulateGeometricAverage(int M, const char * filename) {
  std::ofstream myfile;
  myfile.open(filename);
  myfile << std::setprecision(40);

  simulateAndPrintRelativeError(M, myfile);
  myfile.close();
}
