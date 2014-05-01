/*
 * BoxMullerDice.cpp
 *
 *  Created on: 18.04.2014
 *      Author: boris
 */

#include "BoxMullerDice.h"
#include <cmath>

BoxMullerDice::BoxMullerDice(IUniformDist& _UnifDice) :
  UnifDice(_UnifDice)
{
}

double BoxMullerDice::roll() {
  const double u1 = UnifDice.roll();
  const double u2 = UnifDice.roll();
  return sqrt(-log(u1))*cos(2*M_PI*u2);
}

std::pair<double, double> BoxMullerDice::rollPair() {
  std::pair<double,double> gaussianVector;
  const double u1 = UnifDice.roll();
  const double u2 = UnifDice.roll();
  gaussianVector.first = sqrt(-log(u1))*cos(2*M_PI*u2);
  gaussianVector.second = sqrt(-log(u1))*sin(2*M_PI*u2);
  return gaussianVector;
}
