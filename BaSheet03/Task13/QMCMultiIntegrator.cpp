/*
 * QMCMultiIntegrator.cpp
 *
 *  Created on: 28.05.2014
 *      Author: BlueCrescent
 */

#include "QMCMultiIntegrator.h"
#include "HaltonSequence.h"

#include <vector>
#include <utility>

std::vector<double> generateWeights(const int amount) {
  std::vector<double> weights;
  weights.reserve(amount);
  for (int i = 0; i < amount; ++i)
    weights.push_back(1. / amount);
  return weights;
}

QMCMultiIntegrator::NodesAndWeights QMCMultiIntegrator::getNodesAndWeights(int l, int d) const {
  const int amount = pow(2, l) - 1;
  QMCMultiIntegrator::NodesAndWeights nodesAndWeights;

  nodesAndWeights.Nodes = std::move(generateHaltonSequence(d, amount));
  nodesAndWeights.Weights = std::move(generateWeights(amount));

  return nodesAndWeights;
}
