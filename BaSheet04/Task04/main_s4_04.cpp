/*
 * main_s4_02.cpp
 *
 *  Created on: Jun 20, 2014
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
#include <iostream>
#include <string>

namespace {
  const double S0 = 10.;
  const double r = 0.05;
  const double sigma = 0.2;
  const double T = 1.;
  const double K = 10.;
  const double B = 9.;
  int M = 128;
  const double delta_t = M / T;
}

double evaluateDownOutCallPayoff_fixedB_04(const std::vector<double> & x, double strike) {
  return evaluateDownOutCallPayoff(x, strike, B);
}

double payoffInt_randWalk_downOutCall_04(const std::vector<double> & x) {
  return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genRandomWalkPath, evaluateDownOutCallPayoff_fixedB_04);
}

double payoffInt_brownBridge_downOutCall_04(const std::vector<double> & x) {
  return uniformPayoffIntegrand(x, S0, r, sigma, T, M, K, genBrownianBridgePath, evaluateDownOutCallPayoff_fixedB_04);
}

template<typename EfficientIntegrator>
long double integrateBrownianBridge_downOutCall_04(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate_efficient(level, d, payoffInt_brownBridge_downOutCall_04);
}

template<typename EfficientIntegrator>
long double integrateRandWalk_downOutCall_04(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate_efficient(level, d, payoffInt_randWalk_downOutCall_04);
}

void main_s4_04() {
  const int lMax = 4;
  int d = 1024;
  Cpp11UniformDice dice;

  MCMultiIntegrator mcIntegrator(dice);
  const double numericalRefBB_MC = integrateBrownianBridge_downOutCall_04(mcIntegrator, lMax, 1024);
  const double numericalRefRW_MC = integrateRandWalk_downOutCall_04(mcIntegrator, lMax, 1024);


  std::ofstream f;
  int M_values[4] = {4,64,256,1024};
  for(int M_k : M_values){
    M = M_k;
    d = M;
    f.open("data_s4_04_M=" + std::to_string(M));
    for (int l = 1; l < lMax; ++l) {
      const double valBB_MC = integrateBrownianBridge_downOutCall_04(mcIntegrator, l, d);
      const double valRW_MC = integrateRandWalk_downOutCall_04(mcIntegrator, l, d);

      f << pow(2, l) - 1 << " "
        << fabs(valBB_MC  - numericalRefBB_MC)  / numericalRefBB_MC << " "
        << fabs(valRW_MC  - numericalRefRW_MC)  / numericalRefRW_MC << std::endl;
       std::cout << pow(2, l) - 1 << " "
          << fabs(valBB_MC  - numericalRefBB_MC)  << " "
          << fabs(valRW_MC  - numericalRefRW_MC)  << std::endl;
    }
    f.close();
  }

  std::cout << pow(2, lMax) - 1 << " "
      << fabs(numericalRefBB_MC)  << " "
      << fabs(numericalRefRW_MC)  << std::endl;


}
