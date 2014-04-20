/*
 * Cpp11NormalDice.cpp
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#include "Cpp11NormalDice.h"

#include <ctime>

Cpp11NormalDice::Cpp11NormalDice() {
  this->generator.seed(time_t(NULL));
}

double Cpp11NormalDice::roll() {
  std::normal_distribution<double> distribution;
  return distribution(generator);
}
