/*
 * MCMultiIntegrator.h
 *
 *  Created on: 28.05.2014
 *      Author: timm
 */

#ifndef MCMULTIINTEGRATOR_H_
#define MCMULTIINTEGRATOR_H_

#include "MultiVariateIntegrator.h"
#include "IUniformDist.h"

class MCMultiIntegrator: public MultiVariateIntegrator {
public:
  MCMultiIntegrator(IUniformDist & dice);

  NodesAndWeights getNodesAndWeights(int l, int d) const;

private:
  IUniformDist & dice;

  std::vector<double> generateRandomNode(const int d) const;
};

#endif /* MCMULTIINTEGRATOR_H_ */
