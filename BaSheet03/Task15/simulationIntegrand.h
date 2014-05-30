/*
 * simulationIntegrand.h
 *
 *  Created on: 30.05.2014
 *      Author: BlueCrescent
 */

#ifndef SIMULATIONINTEGRAND_H_
#define SIMULATIONINTEGRAND_H_

#include "PathGenerators.h"

#include <vector>

template<typename WienerPathGen, typename PayoffFunc>
inline double uniformPayoffIntegrand(const std::vector<double> & xUnif, double S0, double r,
                                     double sigma, double T, int M, double strike,
                                     WienerPathGen pathGenFunc, PayoffFunc payoffFunc) {
  const std::vector<double> wienerPath = pathGenFunc(xUnif, T);
  const std::vector<double> geomBMPath = genGeomBMPath(wienerPath, S0, r, sigma, T, M);
  return payoffFunc(geomBMPath, strike);
}



#endif /* SIMULATIONINTEGRAND_H_ */
