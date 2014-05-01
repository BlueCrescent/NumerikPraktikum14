/*
 * GaussLegendreIntegrator.h
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#ifndef GAUSSLEGENDREINTEGRATOR_H_
#define GAUSSLEGENDREINTEGRATOR_H_

#include "NumericalIntegrator.h"

class GaussLegendreIntegrator : public NumericalIntegrator {
public:

  NodesAndWeights getNodesAndWeights(int amount) const;
};

#endif /* GAUSSLEGENDREINTEGRATOR_H_ */
