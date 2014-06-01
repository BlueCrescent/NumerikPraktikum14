/*
 * TrapezoidalIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "TrapezoidalIntegrator.h"

void TrapezoidalIntegrator::generateWeights(NodesAndWeights& returnParam, const double factor, int amount) const {
  if (amount == 1)
    returnParam.Weights.push_back(1.);
  else {
    returnParam.Weights.push_back(3. / 2. * factor);
    for (int i = 1; i < amount - 1; ++i) {
      returnParam.Weights.push_back(factor);
    }
    returnParam.Weights.push_back(3. / 2. * factor);
  }
}

void TrapezoidalIntegrator::generateNodes(NodesAndWeights& returnParam, double factor, int amount) const {
  if (amount == 1)
    returnParam.Nodes.push_back(0.5);
  else {
    returnParam.Nodes.push_back(factor);
    for (int i = 2; i <= amount - 1; ++i) {
      returnParam.Nodes.push_back(factor*i);
    }
    returnParam.Nodes.push_back(factor*amount);
  }
}

TrapezoidalIntegrator::NodesAndWeights TrapezoidalIntegrator::generateLevelOne() const {
  TrapezoidalIntegrator::NodesAndWeights returnParam;
  returnParam.Nodes.push_back(0.5);
  returnParam.Weights.push_back(1.);
  return returnParam;
}

TrapezoidalIntegrator::NodesAndWeights TrapezoidalIntegrator::generateNextLevel(const NodesAndWeights& old) const {
  TrapezoidalIntegrator::NodesAndWeights returnParam;
  const int amount = old.getSize() * 2 + 1;
  const double factor = 1. / ((double) (amount) + 1.);
  returnParam.Weights.push_back(3. / 2. * factor);
  returnParam.Nodes.push_back(factor);
  for (int i = 2; i <= amount - 1; ++i) {
    if (i % 2 == 0)
      returnParam.Nodes.push_back(old.Nodes[i / 2 - 1]);
    else
      returnParam.Nodes.push_back(factor * i);
    returnParam.Weights.push_back(factor);
  }
  returnParam.Weights.push_back(3. / 2. * factor);
  returnParam.Nodes.push_back(factor * amount);
  return returnParam;
}

bool TrapezoidalIntegrator::isLevelZero(const NodesAndWeights& old) const {
  return old.getSize() == 0;
}

TrapezoidalIntegrator::NodesAndWeights TrapezoidalIntegrator::iterateLevel(const NodesAndWeights& old) const {
  return isLevelZero(old) ? generateLevelOne() : generateNextLevel(old);
}

TrapezoidalIntegrator::NodesAndWeights TrapezoidalIntegrator::getNodesAndWeights(int amount) const {
  NodesAndWeights returnParam;
  const double factor = 1./((double)amount +1.);
  generateWeights(returnParam, factor, amount);
  generateNodes(returnParam, factor, amount);
  return returnParam;
}


