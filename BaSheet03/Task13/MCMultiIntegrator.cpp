/*
 * MCMultiIntegrator.cpp
 *
 *  Created on: 28.05.2014
 *      Author: timm
 */

#include "MCMultiIntegrator.h"

#include <vector>
#include <utility>

#include <cmath>

MCMultiIntegrator::MCMultiIntegrator(IUniformDist & _dice) :
dice(_dice)
{
  dice.setBounds(0, 1);
}

std::vector<double> MCMultiIntegrator::generateRandomNode(const int d) const {
  std::vector<double> node;
  node.reserve(d);
  for (int i = 0; i < d; ++i) {
    node.push_back(dice.roll());
  }
  return node;
}

MCMultiIntegrator::NodesAndWeights MCMultiIntegrator::getNodesAndWeights(int l, int d) const {
  const int amount = pow(2, l) - 1;
  MCMultiIntegrator::NodesAndWeights nodesAndWeights(amount);
  for (int i = 0; i < amount; ++i) {
    nodesAndWeights.Weights.push_back(1. / amount);
    nodesAndWeights.Nodes.push_back(std::move(generateRandomNode(d)));
  }
  return nodesAndWeights;
}
