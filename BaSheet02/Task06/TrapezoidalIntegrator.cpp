/*
 * TrapezoidalIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "TrapezoidalIntegrator.h"

void TrapezoidalIntegrator::generateWeights(NodesAndWeights& returnParam, const double factor, int amount) const {
  returnParam.Weights.push_back(3 / 2 * factor);
  for (int i = 1; i < amount - 1; ++i) {
    returnParam.Weights.push_back(factor);
  }
  returnParam.Weights.push_back(3 / 2 * factor);
}

void TrapezoidalIntegrator::generateNodes(NodesAndWeights& returnParam, double factor, int amount) const {
    for (int i = 1; i < amount - 1; ++i) {
      returnParam.Nodes.push_back(factor*i);
    }
}

TrapezoidalIntegrator::NodesAndWeights TrapezoidalIntegrator::getNodesAndWeights(int amount) const {
  NodesAndWeights returnParam;
  const double factor = 1/(amount +1);
  generateWeights(returnParam, factor, amount);
  generateNodes(returnParam, factor, amount);
  return returnParam;
}


