/*
 * ProductIntegrator.cpp
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#include "ProductIntegrator.h"

#include <cassert>

ProductIntegrator::ProductIntegrator(const NumericalIntegrator& _UniVariateIntegrator) :
    UniVariateIntegrator(_UniVariateIntegrator)
{
}

inline bool incrementIndex(std::vector<int>& k, int N_l, int d) {
  for (int j = 0; j < d; ++j) {
    k[j]++;
    if (k[j] > N_l) {
      if (j == d - 1)
        return false;

      k[j] = 1;
    } else
      break;
  }
  return true;
}

inline void genMultiWeightAndNode(const NumericalIntegrator::NodesAndWeights & OneDimVal,
                                  MultiVariateIntegrator::NodesAndWeights & MultiDimVal,
                                  int d, const std::vector<int> & k) {
  std::vector<double> node;
  node.reserve(d);
  double weight = 1;

  for(int j = 0; j < d; ++j) {
    assert(0 <= k[j] - 1 && k[j] - 1 < OneDimVal.getSize());
    weight *= OneDimVal.Weights[k[j] - 1];
    node.push_back(OneDimVal.Nodes[k[j] - 1]);
  }

  MultiDimVal.Weights.push_back(weight);
  MultiDimVal.Nodes.push_back(node);
}

MultiVariateIntegrator::NodesAndWeights ProductIntegrator::getNodesAndWeights(int l, int d) const {
  const int N_l = pow(2, l) - 1;
  const NumericalIntegrator::NodesAndWeights OneDimVal = UniVariateIntegrator.getNodesAndWeights(N_l);
  MultiVariateIntegrator::NodesAndWeights MultiDimVal(pow(N_l, d));
  std::vector<int> k(d, 1);

  do {
    genMultiWeightAndNode(OneDimVal, MultiDimVal, d, k);
  } while (incrementIndex(k, N_l, d));

  return MultiDimVal;
}
