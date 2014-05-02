/*
 * ClenshawIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "ClenshawIntegrator.h"
#include <cmath>

inline void ClenshawIntegrator::generateNodes(const int amount, NodesAndWeights& params) const {
  for (int i = 0; i < amount; ++i) {
      const double node = 0.5*(1. - cos(M_PI * i / (amount + 1.)));
      params.Nodes.push_back(node);
  }
}

inline double weightsInnerSum(const int sumUpper, const  int i, const double factor) {
  double weight_add = 0;
  for (int j = 1; j < sumUpper; ++j) {
    weight_add += 1. / (2. * j - 1.) * sin((2. * j - 1.) * M_PI * i * factor);
  }
  return weight_add;
}

inline void ClenshawIntegrator::generateWeights(const int amount, NodesAndWeights& params) const {
  const double factor = 1. / (amount + 1);
  for (int i = 0; i < amount; ++i) {
    const double weight = 2 * factor * sin(M_PI * i * factor) + weightsInnerSum((amount + 1) / 2, i, factor);
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
