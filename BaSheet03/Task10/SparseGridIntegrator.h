/*
 * SparseGridIntegrator.h
 *
 *  Created on: 21.05.2014
 *      Author: boris
 */

#ifndef SPARSEGRIDINTEGRATOR_H_
#define SPARSEGRIDINTEGRATOR_H_

#include "MultiVariateIntegrator.h"

#include "NumericalIntegrator.h"

class SparseGridIntegrator: public MultiVariateIntegrator {
public:
  SparseGridIntegrator(const HierarchicalIntegrator & univariateIntegrator);

  NodesAndWeights getNodesAndWeights(int l, int d) const;

private:
  const HierarchicalIntegrator & UniVariateIntegrator;

  std::vector<HierarchicalIntegrator::NodesAndWeights> generateOneDimValues(int l) const;
};

#endif /* SPARSEGRIDINTEGRATOR_H_ */
