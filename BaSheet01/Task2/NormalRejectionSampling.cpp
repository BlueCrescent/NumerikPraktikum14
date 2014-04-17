/*
 * NormalRejectionSampling.cpp
 *
 *  Created on: 10.04.2014
 *      Author: boris
 */

#include "NormalRejectionSampling.h"
#include <cmath>

const double NormalRejectionSampling::MaxNormalDensity = 1. / sqrt(2. * M_PI);
const double NormalRejectionSampling::lower = -10;
const double NormalRejectionSampling::upper =  10;

NormalRejectionSampling::NormalRejectionSampling(IUniformDist & UnifDice) :
  UnifDice(UnifDice)
{
}

NormalRejectionSampling::~NormalRejectionSampling() {
}

double NormalRejectionSampling::roll() {
  double x, y;
  do {
    UnifDice.setBounds(lower, upper);
    x = UnifDice.roll();
    UnifDice.setBounds(0, MaxNormalDensity);
    y = UnifDice.roll();
  } while (y <= NormalDensity(x));
  return x;
}

double NormalRejectionSampling::NormalDensity(double x){
  return MaxNormalDensity * exp(- x * x / 2);
}
