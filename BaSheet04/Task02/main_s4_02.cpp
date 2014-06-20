/*
 * main_s4_02.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: boris
 */

#include "Cpp11UniformDice.h"
#include "MCMultiIntegrator.h"
#include "QMCMultiIntegrator.h"
#include "simulationIntegrand.h"
#include "PathGenerators.h"
#include "barrierOptionPayoffs.h"

#include <fstream>
#include <vector>

namespace {
  const double S0 = 10.;
  const double r = 0.05;
  const double sigma = 0.2;
  const double T = 1.;
  const double K = 10.;
  const double B = 9.;
  const int M = 128;
  const double delta_t = M / T;
}

double evaluateDownOutCallPayoff_fixedB(const std::vector<double> & x, double strike) {
  return evaluateDownOutCallPayoff(x, strike, B);
}

double payoffInt_randWalk_downOutCall(const std::vector<double> & x) {
  return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genRandomWalkPath, evaluateDownOutCallPayoff_fixedB);
}

double payoffInt_brownBridge_downOutCall(const std::vector<double> & x) {
  return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genBrownianBridgePath, evaluateDownOutCallPayoff_fixedB);
}

template<typename EfficientIntegrator>
long double integrateBrownianBridge_downOutCall(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate_efficient(level, d, payoffInt_brownBridge_downOutCall);
}

template<typename EfficientIntegrator>
long double integrateRandWalk_downOutCall(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate_efficient(level, d, payoffInt_randWalk_downOutCall);
}

#include <iostream>

void main_s4_02() {
  const int lMax = 4;
  const int d = M;
  Cpp11UniformDice dice;

  MCMultiIntegrator mcIntegrator(dice);
  const double numericalRefBB_MC = integrateBrownianBridge_downOutCall(mcIntegrator, lMax, d);
  const double numericalRefRW_MC = integrateRandWalk_downOutCall(mcIntegrator, lMax, d);
  QMCMultiIntegrator qmcIntegrator;
  const double numericalRefBB_QMC = integrateBrownianBridge_downOutCall(qmcIntegrator, lMax, d);
  const double numericalRefRW_QMC = integrateRandWalk_downOutCall(qmcIntegrator, lMax, d);

  std::ofstream f;
  f.open("data_s4_02");

  for (int l = 1; l < lMax; ++l) {
    const double valBB_MC = integrateBrownianBridge_downOutCall(mcIntegrator, l, d);
    const double valRW_MC = integrateRandWalk_downOutCall(mcIntegrator, l, d);
    const double valBB_QMC = integrateBrownianBridge_downOutCall(qmcIntegrator, l, d);
    const double valRW_QMC = integrateRandWalk_downOutCall(qmcIntegrator, l, d);
    f << pow(2, l) - 1 << " "
      << fabs(valBB_MC  - numericalRefBB_MC)  / numericalRefBB_MC  << " "
      << fabs(valRW_MC  - numericalRefRW_MC)  / numericalRefRW_MC << " "
      << fabs(valBB_QMC - numericalRefBB_QMC) / numericalRefBB_QMC  << " "
      << fabs(valRW_QMC - numericalRefRW_QMC) / numericalRefRW_QMC << std::endl;
     std::cout << pow(2, l) - 1 << " "
//        << fabs(valBB_MC  - numericalRefBB_MC)  << " "
//        << fabs(valRW_MC  - numericalRefRW_MC)  << " "
        << fabs(valBB_QMC  - numericalRefBB_QMC) << " "
        << fabs(valBB_QMC) << " "
//        << fabs(valRW_QMC  - numericalRefRW_QMC)
        << std::endl;
  }

  std::cout << pow(2, lMax) - 1 << " "
      << fabs(numericalRefBB_MC)  << " "
      << fabs(numericalRefRW_MC)  << " "
      << fabs(numericalRefBB_QMC) << " "
      << fabs(numericalRefRW_QMC) << std::endl;

  f.close();
}

