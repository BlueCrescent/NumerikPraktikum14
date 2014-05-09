/*
 * main.cpp
 *
 *  Created on: 09.05.2014
 *      Author: boris
 */


#include "geometricBMdensity.h"
#include "asian_fair_prices.h"
#include <fstream>
#include <iomanip>

void main_s3_05(){
  const int M = 2, evalPointCount = 1000;
  const double T = 1, sigma = 0.25, r = 0.1, start_value = 10, strike = 10;
  const double lowerB = -4, upperB = 4;

  std::ofstream myfile;
  myfile.open("data_s3_05");
  geometricBMdensity densityFunc(r, sigma, start_value);
  for (int i = 0; i <= evalPointCount; i++) {
    const double si = lowerB + i*(upperB-lowerB)/evalPointCount;
    myfile << si << " " << evaluate_discr_arithmetic_payoff(densityFunc(T, M, si), strike) << std::endl;
  }
  myfile.close();
}
