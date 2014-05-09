/*
 * geometricBMdensity.cpp
 *
 *  Created on: 09.05.2014
 *      Author: boris
 */

#include "geometricBMdensity.h"
#include <cmath>

geometricBMdensity::geometricBMdensity(const double _mu, const double _sigma, const double _start_value) :
mu(_mu),
sigma(_sigma),
start_value(_start_value)
{
}

std::vector<double> geometricBMdensity::operator ()(const double T, const int M, const double s) {
  std::vector<double> values;
  for(int i = 1; i <= M; i++){
    const double ti = i*T/M;
     values.push_back(start_value*exp((mu - 0.5*sigma*sigma)*ti + sigma*sqrt(ti)*s));
  }
  return values;
}
