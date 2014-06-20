/*
 * main_s4_09.cpp
 *
 *  Created on: Jun 20, 2014
 *      Author: boris
 */

#include <iostream>

#include "NewtonRaphson.h"

namespace {
  const double S0 = 1312.81;
  const double r = 0.05;
  const double T = 28.;
  const double K = 1275.;
  const unsigned int maxIterations = 1000;

//  double historicalSigma = -1.;
}

//void runTest() {
////  const double startSigma = 10; // computeDefaultSigma<isCall>(S0, r, T, K, historicalSigma, maxIterations);
//
////  std::cout << "Running with sigma = " << startSigma << ". The default sigma would be "
////            << computeDefaultSigma<isCall>(S0, r, T, K, historicalSigma, maxIterations) << "." << std::endl;
//
//  std::cout << "Running with historical sigma = " << historicalSigma
//            << " and start sigma = " <<  startSigma << "." << std::endl;
//  try {
//    const double impliedVolatility = executeNewtonRaphsonAlgo<isCall>(S0, r, T, K, historicalSigma, startSigma, maxIterations);
//    std::cout << "The implied volatility is " << impliedVolatility << "." << std::endl;
//    results[idx++] = impliedVolatility;
//  } catch (NoConvergenceError & error) {
//    std::cout << "No convergence! Last sigma was " << error.getLastSigma() << "." << std::endl;
//    results[idx++] = error.getLastSigma();
//  }
//}

template<bool isCall>
void printResults();

void main_s4_09() {
  double historicalV = 3.710;
  try {
    std::cout << executeNewtonRaphsonAlgo<CALL>(S0, r, T, K, computeDefaultSigma<CALL>(S0, r, T, K,
      maxIterations, historicalV) , maxIterations, historicalV);
  }
  catch(NoConvergenceError& error){
    std::cout << "No convergence! Last sigma was " << error.getLastSigma() << "." << std::endl;
  }
}
