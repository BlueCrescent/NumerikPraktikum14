/*
 * ClenshawIntegrator.h
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#ifndef CLENSHAWINTEGRATOR_H_
#define CLENSHAWINTEGRATOR_H_

#include "NumericalIntegrator.h"

class ClenshawIntegrator: public NumericalIntegrator {
public:
  NodesAndWeights getNodesAndWeights(int amount) const;

private:
  void generateNodes(int amount, NodesAndWeights& params) const;
  void generateWeights(int amount, NodesAndWeights& params) const;
};

#endif /* CLENSHAWINTEGRATOR_H_ */
