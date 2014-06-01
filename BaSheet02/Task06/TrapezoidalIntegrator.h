/*
 * TrapezoidalIntegrator.h
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#ifndef TRAPEZOIDALINTEGRATOR_H_
#define TRAPEZOIDALINTEGRATOR_H_

#include "NumericalIntegrator.h"

class TrapezoidalIntegrator: public HierarchicalIntegrator {
public:
  NodesAndWeights getNodesAndWeights(int amount) const;

  NodesAndWeights iterateLevel(const NodesAndWeights& old) const;

private:
  void generateWeights(NodesAndWeights& returnParam, double factor, int amount) const;
  void generateNodes(NodesAndWeights& returnParam, double factor, int amount) const;

  TrapezoidalIntegrator::NodesAndWeights generateLevelOne() const;
  TrapezoidalIntegrator::NodesAndWeights generateNextLevel(const NodesAndWeights& old) const;
  bool isLevelZero(const NodesAndWeights& old) const;
};

#endif /* TRAPEZOIDALINTEGRATOR_H_ */
