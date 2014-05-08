/*
 * MonteCarloIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "MonteCarloIntegrator.h"
#include "Cpp11UniformDice.h"

inline void generateNodes(const int amount, MonteCarloIntegrator::NodesAndWeights & params) {
  Cpp11UniformDice Dice;
  for (int i = 0; i < amount; ++i)
    params.Nodes.push_back(Dice.roll());
}

MonteCarloIntegrator::NodesAndWeights MonteCarloIntegrator::getNodesAndWeights(int amount) const {
  NodesAndWeights params;
  generateNodes(amount, params);
  params.Weights.assign(amount, 1. / amount);
  return params;
}
