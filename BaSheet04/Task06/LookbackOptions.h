/*
 * LookbackOptions.h
 *
 *  Created on: Jun 19, 2014
 *      Author: boris
 */

#ifndef LOOKBACKOPTIONS_H_
#define LOOKBACKOPTIONS_H_

#include <vector>

#include <cmath>

#include "closedFormSolutions.h"

inline double evalDiscrLookbackPayoff(const std::vector<double> & PathValues, const double strike) {
  double currentMax = 0.;
  for(unsigned int i = 0; i < PathValues.size(); i++){
    currentMax = PathValues[i] > currentMax ? PathValues[i] : currentMax;
  }
  return currentMax > strike ? currentMax - strike : 0.;
}

inline double compDiscrLookbackFairPrice(double S0, double r, double sigma, double T, double K, int M) {
  const double discountFactor = exp(- r * T);
  const double part1 = discountFactor * (S0 - K);
  const double part2 = computeEuropeanCallClosedForm(S0, r, sigma, T, S0);
  const double part3 = S0 * sigma * sigma / (2 * r);
  const double part4 = NormalCDF(comp_d(S0, r, sigma, T, S0) + sigma * sqrt(T));
  const double part5 = discountFactor * NormalCDF(- comp_d(S0, r, sigma, T, S0));

  return part1 + part2 + part3 * (part4 - part5);
}


#endif /* LOOKBACKOPTIONS_H_ */
