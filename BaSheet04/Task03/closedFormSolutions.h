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

// This is d2, NOT d1! (cf. sheet 4 page 2 formula 7)
inline double comp_d(double S0, double r, double sigma, double T, double K) {
  return (log(S0 / K) + (r - sigma * sigma / 2.) * T) / (sigma * sqrt(T));
}

inline double computeEuropeanCallClosedForm(double S0, double r, double sigma, double T, double K) {
  const double d = comp_d(S0, r, sigma, T, K);
  return S0 * NormalCDF(d + sigma * sqrt(T)) - K * exp(- r * T) * NormalCDF(d);
}

inline double computeDownOutCallClosedForm(double S0, double r, double sigma, double T, double K, double B) {
  const double Bbar = fmax(B, K);
  const double Z = pow(B / S0, 2. * r / (sigma * sigma) - 1);

  const double part1 = computeEuropeanCallClosedForm(S0, r, sigma, T, Bbar);
  const double part2 = Z * computeEuropeanCallClosedForm(B * B / S0, r, sigma, T, Bbar);
  const double part3 = (Bbar - K) * exp(- r * T);
  const double part4 = NormalCDF(comp_d(S0, r, sigma, T, Bbar));
  const double part5 = Z * NormalCDF(comp_d(B * B / S0, r, sigma, T, Bbar));

  return part1 - part2 + part3 * (part4 - part5);
}

#endif /* CLOSEDFORMSOLUTIONS_H_ */
