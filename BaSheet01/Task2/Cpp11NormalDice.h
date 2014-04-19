/*
 * Cpp11NormalDice.h
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#ifndef CPP11NORMALDICE_H_
#define CPP11NORMALDICE_H_

#include <random>
#include "INormalDist.h"

class Cpp11NormalDice: public INormalDistribution {
public:
  Cpp11NormalDice();

  ~Cpp11NormalDice();

  double roll();

private:
  std::default_random_engine generator;
};

#endif /* CPP11NORMALDICE_H_ */
