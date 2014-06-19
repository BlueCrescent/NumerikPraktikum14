/*
 * closedFormSolutions.h
 *
 *  Created on: Jun 6, 2014
 *      Author: boris
 */

#ifndef CLOSEDFORMSOLUTIONS_H_
#define CLOSEDFORMSOLUTIONS_H_

#include "NormalCDF.h"

#include <cmath>

inline double d(double S0, double r, double sigma, double T, double K) {
  return (log(S0 / K) + (r - sigma * sigma / 2.) * T) / (sigma * sqrt(T));
}

inline double computeEuropeanCallClosedForm(double S0, double r, double sigma, double T, double K) {
  const double d = d(S0, r, sigma, T, K);
  return S0 * NormalCDF(d + sigma * sqrt(T)) - K * exp(- r * T) * NormalCDF(d);
}

inline double computeDownOutCallClosedForm(double S0, double r, double sigma, double T, double K, double B) {
  const double Bbar = std::max(B, K);
#error "This is not done yet."
}

#endif /* CLOSEDFORMSOLUTIONS_H_ */
