/*
 * MonteCarloIntegrator.h
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#ifndef MONTECARLOINTEGRATOR_H_
#define MONTECARLOINTEGRATOR_H_

#include "NumericalIntegrator.h"

class MonteCarloIntegrator : public NumericalIntegrator{
  NodesAndWeights getNodesAndWeights(int amount) const;
};

#endif /* MONTECARLOINTEGRATOR_H_ */
