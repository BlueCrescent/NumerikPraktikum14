/*
 * ClenshawIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "ClenshawIntegrator.h"
#include <cmath>

void ClenshawIntegrator::generateNodes(int amount, NodesAndWeights& params) const {
  double node;
  for (int i = 0; i < amount; ++i) {
      node = 0.5*(1 - cos((double)M_PI * i / (amount + 1)));
      params.Nodes.push_back(node);
  }
}

void ClenshawIntegrator::generateWeights(int amount, NodesAndWeights& params) const {
  double weight;
  double factor = 2. / amount;
  amount++; // we only use amount + 1
  for (int i = 0; i < amount - 1; ++i) {
    weight = 0;
    for (int j = 1; j < amount / 2; ++j) {
      weight += 1. / (2. * j - 1) * sin((2.*j - 1) * M_PI * i / amount);
    }
    weight *= sin(M_PI * i / amount) * factor;
    params.Weights.push_back(weight);
  }
}

ClenshawIntegrator::NodesAndWeights
ClenshawIntegrator::getNodesAndWeights(int amount) const {
  NodesAndWeights params;
  generateNodes(amount, params);
  generateWeights(amount, params);
  return params;
}
