/*
 * asian_fair_prices.cpp
 *
 *  Created on: 08.05.2014
 *      Author: boris
 */

#include "asian_fair_prices.h"
#include "NormalCDF.h"

#include <cmath>

double calc_discrete_geometric_fairP(double start_value, double r, double sigma, double strike, double T, unsigned int M) {
  const double delta_t = T / M;
  const double T_2 = T - (M - 1.) / 2. * delta_t;
  const double T_1 = T - M * (M - 1.) * (4. * M + 1.) / (6. * M * M) * delta_t;
  const double d = (log(start_value / strike) + (r - 1. / 2. * sigma * sigma) * T_2) / (sigma * sqrt(T_1));
  const double A = exp(- r * (T - T_2) - sigma * sigma * (T_2 - T_1) / 2.);

  return start_value * A * NormalCDF(d + sigma * sqrt(T_1)) - strike * exp(- r * T) * NormalCDF(d);
}

double calc_continious_geometric_fairP(double start_value, double r, double sigma, double strike, double T) {

  const double d = (log(start_value / strike) + 0.5 * (r - 0.5 * sigma * sigma) * T) / (sigma * sqrt(T / 3.));
  const double part1 = start_value * exp(0.5 * ( r + 1. / 6. * sigma * sigma) * T);
  const double part2 = NormalCDF(d + sigma * sqrt(T / 3.));
  return part1 * part2 - strike * exp(- r * T) * NormalCDF(d);
}

double evaluate_discr_geometric_payoff(const std::vector<double>& PathValues, double strike) {
  double product = 1;
  for(unsigned int i = 0; i < PathValues.size(); i++){
    product *= PathValues[i];
  }
  const double average = pow(product, 1. / PathValues.size())- strike;
  return average > 0 ? average : 0;
}

double evaluate_discr_arithmetic_payoff(const std::vector<double>& PathValues, double strike) {
  double sum = 0;
  for(unsigned int i = 0; i < PathValues.size(); i++){
    sum += PathValues[i];
  }
  const double average = sum / PathValues.size() - strike;
  return average > 0 ? average : 0;
}
