#include "PathGenerators.h"
#include "simulationIntegrand.h"
#include "asian_fair_prices.h"
#include "SparseGridIntegrator.h"
#include "ClenshawIntegrator.h"

#include <vector>

#include <cmath>

namespace {
  const double S0 = 10.;
  const double r = 0.1;
  const double sigma = 0.25;
  const double T = 1.;
  const double K = 0.;
  const int M = 16;
  const double delta_t = M / T;
}

double payoffInt_randWalkDiscrGeom(const std::vector<double> & x) {
  return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genRandomWalkPath, evaluate_discr_geometric_payoff);
}

double payoffInt_brownianBridgeDiscrGeom(const std::vector<double> & x) {
  return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genBrownianBridgePath, evaluate_discr_geometric_payoff);
}

#include <iostream>

void main_s3_15() {
  const ClenshawIntegrator integrator1D;
  const SparseGridIntegrator multivariateIntegrator(integrator1D);

  std::cout << "randWalk: "
            << multivariateIntegrator.integrate(4, M, payoffInt_randWalkDiscrGeom)
            << std::endl;
  std::cout << "brownBridge: "
            << multivariateIntegrator.integrate(4, M, payoffInt_brownianBridgeDiscrGeom)
            << std::endl;

}
