/*
 * GSLUniformDice.cpp
 *
 *  Created on: 17.04.2014
 *      Author: timm
 */

#include "GSLUniformDice.h"

#include <new>

GSLUniformDice::GSLUniformDice() :
  Lower(0),
  Upper(1),
  RandomGenerator(gsl_rng_alloc(gsl_rng_mt19937))
{
  if (RandomGenerator == NULL)
    throw new std::bad_alloc();
}

GSLUniformDice::~GSLUniformDice() {
  gsl_rng_free(RandomGenerator);
}

double GSLUniformDice::roll() {
  return Lower + (Upper - Lower) * gsl_rng_uniform(RandomGenerator);
}

void GSLUniformDice::setBounds(double _Lower, double _Upper) {
  Lower = _Lower;
  Upper = _Upper;
}
