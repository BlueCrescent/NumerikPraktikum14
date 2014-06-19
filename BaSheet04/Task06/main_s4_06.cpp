/*
 * main_s4_06.cpp
 *
 *  Created on: Jun 19, 2014
 *      Author: boris
 */

#include <fstream>

#include "Cpp11UniformDice.h"
#include "MCMultiIntegrator.h"
#include "QMCMultiIntegrator.h"
#include "LookbackOptions.h"
#include "simulationIntegrand.h"
#include "PathGenerators.h"

namespace {
  const double S0 = 10.;
  const double r = 0.05;
  const double sigma = 0.2;
  const double T = 1.;
  const double K = 10.;
  const int M = 128;

  double payoffInt_brownianBridgeDiscrLookback(const std::vector<double> & x) {
    return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genBrownianBridgePath, evalDiscrLookbackPayoff);
  }

  template<typename EfficientIntegrator>
  long double integrateDiscrLookBack_brownianBridg(const EfficientIntegrator & tmp, const int level, const int d){
    return exp(- r * T) * tmp.integrate_efficient(level, d, payoffInt_brownianBridgeDiscrLookback);
  }
}

void printConvergenceDataLookback(std::ofstream& out) {
  Cpp11UniformDice Dice;
  const double exact = compDiscrLookbackFairPrice(S0, r, sigma, T, K, M);
  for (int l = 1; l < 6; ++l) {
    out << pow(2, l) - 1 << " ";
    out << fabs(integrateDiscrLookBack_brownianBridg(MCMultiIntegrator(Dice), l, M) - exact ) / exact << " ";
    out << fabs(integrateDiscrLookBack_brownianBridg(QMCMultiIntegrator(), l, M)    - exact ) / exact << " ";
    out << std::endl;
  }
}


void main_s4_06() {
  std::ofstream out;
  out.open("data_s4_06");
  printConvergenceDataLookback(out);
  out.close();
}
