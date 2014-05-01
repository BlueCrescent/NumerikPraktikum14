/*
 * TrapezoidalIntegrator.h
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#ifndef TRAPEZOIDALINTEGRATOR_H_
#define TRAPEZOIDALINTEGRATOR_H_

#include "NumericalIntegrator.h"

class TrapezoidalIntegrator: public NumericalIntegrator {
public:
  NodesAndWeights getNodesAndWeights(int amount) const;

private:
  void generateWeights(NodesAndWeights& returnParam, double factor, int amount) const;
  void generateNodes(NodesAndWeights& returnParam, double factor, int amount) const;
};

#endif /* TRAPEZOIDALINTEGRATOR_H_ */
