/*
 * ClenshawIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "ClenshawIntegrator.h"
#include <cmath>

inline void ClenshawIntegrator::generateNodes(const int amount, NodesAndWeights& params) const {
  const double factor = M_PI / (amount + 1.);
  for (int i = 1; i <= amount; ++i) {
      const double node = 0.5 * (1. - cos(i * factor));
      params.Nodes.push_back(node);
  }
}

inline double weightInnerSum(const int sumUpper, const double piFactor) {
  double weightSum = 0.;
  for (int j = 1; j <= sumUpper; ++j) {
    weightSum += 1. / (2. * j - 1.) * sin((2. * j - 1.) * piFactor);
  }
  return weightSum;
}

inline void ClenshawIntegrator::generateWeights(const int amount, NodesAndWeights& params) const {
  const double factor = 1. / (amount + 1.);
  for (int i = 1; i <= amount; ++i) {
    const double piFactor = M_PI * i * factor;
    const double weight = 2. * factor * sin(piFactor) * weightInnerSum((amount + 1) / 2, piFactor);
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
