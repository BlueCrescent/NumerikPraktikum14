/*
 * main_s3_16.cpp
 *
 *  Created on: 01.06.2014
 *      Author: BlueCrescent
 */

#include "PathGenerators.h"
#include "simulationIntegrand.h"
#include "asian_fair_prices.h"
#include "SparseGridIntegrator.h"
#include "TrapezoidalIntegrator.h"
#include "ClenshawIntegrator.h"
#include "ProductIntegrator.h"
#include "SparseGridIntegrator.h"
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
  const double K = 0.;
  const int M = 8;
  const double delta_t = M / T;

  double payoffInt_randWalkDiscrGeom(const std::vector<double> & x) {
    return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genRandomWalkPath, evaluate_discr_geometric_payoff);
  }

  double payoffInt_brownianBridgeDiscrGeom(const std::vector<double> & x) {
    return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genBrownianBridgePath, evaluate_discr_geometric_payoff);
  }
}

double integrateRandomWalk_discFactor(const MultiVariateIntegrator& tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate(level, d, payoffInt_randWalkDiscrGeom);
}

double integrateBrownianBridge_discFactor(const MultiVariateIntegrator& tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate(level, d, payoffInt_brownianBridgeDiscrGeom);
}

template <typename EfficientIntegrator>
double integrateRandomWalk_discFactorEfficient(const EfficientIntegrator& tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrateEfficient(level, d, payoffInt_randWalkDiscrGeom);
}

template <typename EfficientIntegrator>
double integrateBrownianBridge_discFactorEfficient(const EfficientIntegrator& tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrateEfficient(level, d, payoffInt_brownianBridgeDiscrGeom);
}

void printAllIntegrationPoints(std::ofstream& out) {
  const TrapezoidalIntegrator TrapezRule;
  const ClenshawIntegrator ClenshawRule;
  Cpp11UniformDice Dice;
  SparseGridIntegrator NodeSizer(TrapezRule);
  const double exact = calc_discrete_geometric_fairP(S0, r, sigma, K, T, M);
  for (int l = 1; l < 4; ++l) {
    out << pow(2, l * M) - 1 << " ";
    out << pow(pow(2, l) - 1, M) << " ";
    out << NodeSizer.getNodesAndWeights(2 * l, M).getSize() << " ";
    out << fabs(integrateRandomWalk_discFactorEfficient(MCMultiIntegrator(Dice), l * M, M)            - exact ) / exact << " ";
    out << fabs(integrateRandomWalk_discFactorEfficient(QMCMultiIntegrator(), l * M, M)               - exact ) / exact << " ";
    out << fabs(integrateRandomWalk_discFactorEfficient(ProductIntegrator(TrapezRule), l, M)      - exact ) / exact << " ";
    out << fabs(integrateRandomWalk_discFactorEfficient(ProductIntegrator(ClenshawRule), l, M)    - exact ) / exact << " ";
    out << fabs(integrateRandomWalk_discFactor(SparseGridIntegrator(TrapezRule), 2 * l, M)   - exact ) / exact << " ";
    out << fabs(integrateRandomWalk_discFactor(SparseGridIntegrator(ClenshawRule), 2 * l, M) - exact ) / exact << " ";

    out << fabs(integrateBrownianBridge_discFactorEfficient(MCMultiIntegrator(Dice), l * M, M)            - exact ) / exact << " ";
    out << fabs(integrateBrownianBridge_discFactorEfficient(QMCMultiIntegrator(), l * M, M)               - exact ) / exact << " ";
    out << fabs(integrateBrownianBridge_discFactorEfficient(ProductIntegrator(TrapezRule), l, M)      - exact ) / exact << " ";
    out << fabs(integrateBrownianBridge_discFactorEfficient(ProductIntegrator(ClenshawRule), l, M)    - exact ) / exact << " ";
    out << fabs(integrateBrownianBridge_discFactor(SparseGridIntegrator(TrapezRule), 2 * l, M)   - exact ) / exact << " ";
    out << fabs(integrateBrownianBridge_discFactor(SparseGridIntegrator(ClenshawRule), 2 * l, M) - exact ) / exact << " ";
    out << std::endl;
  }
}

void main_s3_16() {
  std::ofstream out;
  out.open("data_s3_16");
  printAllIntegrationPoints(out);
  out.close();
}

