/*
 * MonteCarloIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include <Task09/MonteCarloIntegrator.h>

MonteCarloIntegrator::NodesAndWeights MonteCarloIntegrator::getNodesAndWeights(int amount) const {
  NodesAndWeights params;
  params.Nodes.assign(amount,1);
  params.Weights.assign(amount,1);
  return params;
}
