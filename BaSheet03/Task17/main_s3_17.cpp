/*
 * main_s3_17.cpp
 *
 *  Created on: 01.06.2014
 *      Author: BlueCrescent
 */

#include "PathGenerators.h"
#include "simulationIntegrand.h"
#include "asian_fair_prices.h"
#include "MCMultiIntegrator.h"
#include "QMCMultiIntegrator.h"
#include "Cpp11UniformDice.h"

#include <fstream>
#include <string>

#include <cmath>

namespace {
  const double S0 = 10.;
  const double r = 0.1;
  const double sigma = 0.25;
  const double T = 1.;
  const double K = 10.;
  const int M = 64;
  const double delta_t = M / T;

  double payoffInt_randWalkDiscrGeom(const std::vector<double> & x) {
    return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genRandomWalkPath, evaluate_discr_geometric_payoff);
  }

  double payoffInt_brownianBridgeDiscrGeom(const std::vector<double> & x) {
    return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genBrownianBridgePath, evaluate_discr_geometric_payoff);
  }
}

template<typename EfficientIntegrator>
long double integrateRandomWalk_discFactor17(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate_efficient(level, d, payoffInt_randWalkDiscrGeom);
}

template<typename EfficientIntegrator>
long double integrateBrownianBridge_discFactor17(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate_efficient(level, d, payoffInt_brownianBridgeDiscrGeom);
}

void printAllIntegrationPoints17(std::ofstream& out) {
  Cpp11UniformDice Dice;
  const double exact = calc_discrete_geometric_fairP(S0, r, sigma, K, T, M);
  for (int l = 1; l < 6; ++l) {
    out << l << " ";
    out << fabs(integrateRandomWalk_discFactor17(MCMultiIntegrator(Dice), l, M)     - exact ) / exact << " ";
    out << fabs(integrateRandomWalk_discFactor17(QMCMultiIntegrator(), l, M)        - exact ) / exact << " ";

    out << fabs(integrateBrownianBridge_discFactor17(MCMultiIntegrator(Dice), l, M) - exact ) / exact << " ";
    out << fabs(integrateBrownianBridge_discFactor17(QMCMultiIntegrator(), l, M)    - exact ) / exact << " ";
    out << std::endl;
  }
}

void main_s3_17() {
  std::ofstream out;
  out.open("data_s3_17");
  printAllIntegrationPoints17(out);
  out.close();
}

