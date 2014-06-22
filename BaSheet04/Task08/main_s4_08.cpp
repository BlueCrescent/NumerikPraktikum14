/*
 * main_s4_08.cpp
 *
 *  Created on: 22.06.2014
 *      Author: BlueCrescent
 */

#include "bisectionMethod.h"
#include "closedFormSolutions.h"

#include <iostream>

class EuropeanCallVolatilityFunction {
public:

  double operator()(double sigma) const {
    return computeEuropeanCallClosedForm(S0, r, sigma, T, K) - historicalV;
  }

  const double historicalV;
  const double S0, r, T, K;
};



void main_s4_08() {
  const double S0 = 1312.81 / 20000.;
  const double r = 0.275;
  const double T = 28.;
  const double K = 1275.;
  const double historicalV = 3.710 / 20000.;

  const unsigned int maxIterations = 10000;

  double ivalLeft = 0., ivalRight = 5.;

  const EuropeanCallVolatilityFunction func{historicalV, S0, r, T, K};

  try {
    const double sigma = executeBisectionMethod(func, ivalLeft, ivalRight, maxIterations);
    std::cout << "  The implied volatility is " << sigma << "." << std::endl;
  } catch(Bisection_InvalidSearchIntervalException & error) {
    std::cout << "  Invalid search interval exception caught." << std::endl;
  } catch(Bisection_NoConvergenceError & error) {
    std::cout << "  No convergence! Last interval was: " << error.left << ", " << error.right << std::endl;
  }
}
