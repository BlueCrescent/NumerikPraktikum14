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
#include "closedFormSolutions.h"

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

  int M = -1;
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
  return exp(- r * T) * tmp.integrateEfficient(level, d, payoffInt_brownBridge_downOutCall_04);
}

template<typename EfficientIntegrator>
long double integrateRandWalk_downOutCall_04(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrateEfficient(level, d, payoffInt_randWalk_downOutCall_04);
}

template<typename EfficientIntegrator>
long double integrateBrownianBridge_downOutCall_04_2(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate(level, d, payoffInt_brownBridge_downOutCall_04);
}

template<typename EfficientIntegrator>
long double integrateRandWalk_downOutCall_04_2(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrate(level, d, payoffInt_randWalk_downOutCall_04);
}

void generateConvergencePlotDataMC_DownOutCall(int M_timeDiscr, const int lMax_MC, const double refValue) {
  Cpp11UniformDice dice;
  MCMultiIntegrator mcIntegrator(dice);
  std::ofstream f;

  M = M_timeDiscr;
  f.open("data_s4_04_M=" + std::to_string(M_timeDiscr));

//  std::cout << "lMax = " << lMax_MC << ", d = " << M_timeDiscr << ":" << std::endl;
  for (int l = 1; l < lMax_MC; ++l) {
    const double valBB_MC = integrateBrownianBridge_downOutCall_04(mcIntegrator, l, M_timeDiscr);
    const double valRW_MC = integrateRandWalk_downOutCall_04(mcIntegrator, l, M_timeDiscr);
    f << pow(2, l) - 1
      << " " << fabs(valBB_MC - refValue) / refValue
      << " " << fabs(valRW_MC - refValue) / refValue << std::endl;
//    std::cout << pow(2, l) - 1
//      << " " << fabs(valBB_MC - refValue)
//      << " " << fabs(valRW_MC - refValue) << std::endl;
//    const double valBB_MC_2 = integrateBrownianBridge_downOutCall_04_2(mcIntegrator, l, M_timeDiscr);
//    const double valRW_MC_2 = integrateRandWalk_downOutCall_04_2(mcIntegrator, l, M_timeDiscr);
//    std::cout << pow(2, l) - 1
//      << " " << (valBB_MC - valBB_MC_2) << " " << valBB_MC << " " << valBB_MC_2 << std::endl
//      << "       " << (valRW_MC - valRW_MC_2) << " " << valRW_MC << " " << valBB_MC_2 << std::endl;
  }

  f.close();
}

void main_s4_04() {
  const int lMax_MC = 7;

  const double refValue = computeDownOutCallClosedForm(S0, r, sigma, T, K, B);

  const int M_DownOutCall_values[4] = {4, 64, 256, 1024};

//  const int M_DownOutCall_values[1] = {1};

  for(int M_k : M_DownOutCall_values){
    generateConvergencePlotDataMC_DownOutCall(M_k, lMax_MC, refValue);
  }
}
