/*
 * MonteCarloIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "MonteCarloIntegrator.h"

inline void generateNodes(const int amount, MonteCarloIntegrator::NodesAndWeights & params) {
  const double step = 1. / amount;
  for (double nodeVal = step / 2.; nodeVal < 1.; nodeVal += step)
    params.Nodes.push_back(nodeVal);
}

MonteCarloIntegrator::NodesAndWeights MonteCarloIntegrator::getNodesAndWeights(int amount) const {
  NodesAndWeights params;
  generateNodes(amount, params);
  params.Weights.assign(amount, 1. / amount);
  return params;
}
