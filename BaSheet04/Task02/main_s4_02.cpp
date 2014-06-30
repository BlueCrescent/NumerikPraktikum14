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
#include <string>

using namespace std;
namespace {
  const double S0 = 10.;
  const double r = 0.05;
  const double sigma = 0.2;
  const double T = 1.;
  const double K = 10.;
  const double B = 9.;
  const int M = 128;
  const double delta_t = M / T;

  const int lMax = 20;
  vector<double> BBMC;
  vector<double> BBQMC;
  vector<double> RWMC;
  vector<double> RWQMC;
}

//const vector<double>& BBMC, const vector<double>& BBQMC, const vector<double>& RWMC, const vector<double>& RWQMC,
void fillPlotFile(const int refIndex, string FName);

void createPlotData();

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
  return exp(- r * T) * tmp.integrateEfficient(level, d, payoffInt_brownBridge_downOutCall);
}

template<typename EfficientIntegrator>
long double integrateRandWalk_downOutCall(const EfficientIntegrator & tmp, const int level, const int d){
  return exp(- r * T) * tmp.integrateEfficient(level, d, payoffInt_randWalk_downOutCall);
}

#include <iostream>

void main_s4_02() {
  createPlotData();
  fillPlotFile(lMax-1, "data_s4_02");
  fillPlotFile(lMax-5, "data_s4_02_2");
}

void fillPlotFile(const int refIndex, string FName){
  std::ofstream file;
  file.open(FName);
  if(BBQMC[refIndex] == 0){
    cout<< "WARNING: Reference Value is 0!" << endl;
    return;
  }
  for (int l = 1; l < lMax; ++l) {
    if(l - 1 == refIndex)
      continue;
    file << pow(2, l) - 1 <<
     " " << fabs(BBMC[l-1] - BBMC[refIndex])   / BBMC[refIndex] <<
     " " << fabs(RWMC[l-1] - RWMC[refIndex])   / RWMC[refIndex] <<
     " " << fabs(BBQMC[l-1] - BBQMC[refIndex]) / BBQMC[refIndex] <<
     " " << fabs(RWQMC[l-1] - RWQMC[refIndex]) / RWQMC[refIndex] << std::endl;
  }
  file.close();
}

void createPlotData(){
  Cpp11UniformDice dice;
  MCMultiIntegrator mcIntegrator(dice);
  QMCMultiIntegrator qmcIntegrator;
  for(int i = 1; i <= lMax; ++i){
    BBMC.push_back(integrateBrownianBridge_downOutCall(mcIntegrator, i, M));
    BBQMC.push_back(integrateBrownianBridge_downOutCall(qmcIntegrator, i, M));
    RWMC.push_back(integrateRandWalk_downOutCall(mcIntegrator, i, M));
    RWQMC.push_back(integrateRandWalk_downOutCall(qmcIntegrator, i, M));
  }
}

// OLD Functions, will get usefull once

void fillPlotFile2_2_old(const string FName, const vector<double>& values){
  std::ofstream file;
//  for(int ref = lMax-1; ref >= 0; --ref){
//    cout << values[ref] << " ";
//  }
//  cout << endl;
  file.open(FName);
  for(int lSim = 1; lSim <= lMax; lSim++){
    file << pow(2,lSim)-1 << " ";
    for(int ref = lMax-1; ref >= lSim-1; --ref){
//      if(values[ref] == 0)
//        cout<< FName <<  " ref: " << ref <<  " sim: " << lSim << endl;
      file << fabs((values[lSim - 1]  - values[ref])  / values[ref]) << " ";
    }
    file << endl;
  }
  file.close();
}

void executeTask2_2_old(const vector<double>& BBMC, const vector<double>& BBQMC, const vector<double>& RWMC, const vector<double>& RWQMC){
  fillPlotFile2_2_old("data_s4_021_BBMC",  BBMC);
  fillPlotFile2_2_old("data_s4_021_BBQMC", BBQMC);
  fillPlotFile2_2_old("data_s4_021_RWMC",  RWMC);
  fillPlotFile2_2_old("data_s4_021_RWQMC", RWQMC);
}

void executeTask2_1_old() {
//  const int lMax = 10;
  const int d = M;
  Cpp11UniformDice dice;
  MCMultiIntegrator mcIntegrator(dice);
  const double refBB_MC = integrateBrownianBridge_downOutCall(mcIntegrator, lMax, d);
  const double refRW_MC = integrateRandWalk_downOutCall(mcIntegrator, lMax, d);
  QMCMultiIntegrator qmcIntegrator;
  const double refBB_QMC = integrateBrownianBridge_downOutCall(qmcIntegrator, lMax, d);
  const double refRW_QMC = integrateRandWalk_downOutCall(qmcIntegrator, lMax, d);
  std::ofstream file;
  file.open("data_s4_02");
  for (int l = 1; l <= lMax; ++l) {
    const double valBB_MC = integrateBrownianBridge_downOutCall(mcIntegrator, l, d);
    const double valRW_MC = integrateRandWalk_downOutCall(mcIntegrator, l, d);
    const double valBB_QMC = integrateBrownianBridge_downOutCall(qmcIntegrator, l, d);
    const double valRW_QMC = integrateRandWalk_downOutCall(qmcIntegrator, l, d);
    cout << valRW_QMC << " ";
    file << pow(2, l) - 1 << " " << fabs(valBB_MC - refBB_MC) / refBB_MC << " " << fabs(valRW_MC - refRW_MC) / refRW_MC
        << " " << fabs(valBB_QMC - refBB_QMC) / refBB_QMC << " " << fabs(valRW_QMC - refRW_QMC) / refRW_QMC
        << std::endl;
//    std::cout << "Simulations: " << pow(2, l) - 1 << std::endl << " MC | BB: " << fabs(refBB_MC) << " - " << valBB_MC
//        << " --> " << fabs(valBB_MC - refBB_MC) / refBB_MC << " " << std::endl << "QMC | BB: " << fabs(refBB_QMC)
//        << " - " << valBB_QMC << " --> " << fabs(valBB_QMC - refBB_QMC) / refBB_QMC << " " << std::endl << " MC | RW: "
//        << fabs(refRW_MC) << " - " << valRW_MC << " --> " << fabs(valRW_MC - refRW_MC) / refRW_MC << " " << std::endl
//        << "QMC | RW: " << fabs(refRW_QMC) << " - " << valRW_QMC << " --> " << fabs(valRW_QMC - refRW_QMC) / refRW_QMC
//        << " " << std::endl;
//    std::cout << std::endl;
  }
  file.close();
}
