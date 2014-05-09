/*
 * main.cpp
 *
 *  Created on: 08.05.2014
 *      Author: boris
 */

#include "geometricBM.h"
#include "Cpp11NormalDice.h"
#include "asian_fair_prices.h"

#include <fstream>
#include <iomanip>
#include <cmath>

void simulateGeometricAverage(int M, double delta_t, const char * filename);

void main_s3_03() {
  const int M1 = 10, M2 = 200;
  const double delta1 = 0.1, delta2 = 0.005;

  simulateGeometricAverage(M1, delta1, "data_s3_03_M10");
  simulateGeometricAverage(M2, delta2, "data_s3_03_M200");
}

void simulateAndPrintRelativeError(double delta_t, int M, std::ostream& outStream) {
  const double start_value = 10, r = 0.1, sigma = 0.25, strike = 10, T = 1.;
  const geometricBMParameter Parameters {start_value, r, sigma, delta_t};
  Cpp11NormalDice Dice;

  const double expectedPayoff1 = calc_discrete_geometric_fairP(start_value, r, sigma, strike, T, M);

  double sum = 0;
  for (int i = 1; i < 10000; i++) {
    geometricBM Path(Parameters, Dice);
    const std::vector<double> values = Path.compute_path_values(M);
    sum += evaluate_discr_geometric_payoff(values, strike);
    outStream << i << " " << fabs(sum / i - expectedPayoff1) / expectedPayoff1 << std::endl;
  }
}

void simulateGeometricAverage(int M, double delta_t, const char * filename) {
  std::ofstream myfile;
  myfile.open(filename);
  myfile << std::setprecision(40);

  simulateAndPrintRelativeError(delta_t, M, myfile);
  myfile.close();
}
