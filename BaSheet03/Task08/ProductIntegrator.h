/*
 * ProductIntegrator.h
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#ifndef PRODUCTINTEGRATOR_H_
#define PRODUCTINTEGRATOR_H_

#include "MultiVariateIntegrator.h"
#include "NumericalIntegrator.h"

class ProductIntegrator : public MultiVariateIntegrator {
public:
  ProductIntegrator(const NumericalIntegrator& UniVariateIntegrator);

  NodesAndWeights getNodesAndWeights(int l, int d) const;

private:
  const NumericalIntegrator& UniVariateIntegrator;

};

#endif /* PRODUCTINTEGRATOR_H_ */
