/*
 * ProductIntegrator.cpp
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#include "ProductIntegrator.h"

ProductIntegrator::ProductIntegrator(const NumericalIntegrator& _UniVariateIntegrator) :
    UniVariateIntegrator(_UniVariateIntegrator)
{
}

inline bool incrementIndex(const std::vector<int>& k, int N_l, int d) const {
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
    weight *= OneDimVal.Weights[k[j]];
    node[j] = OneDimVal.Nodes[k[j]];
  }

  MultiDimVal.Weights.push_back(weight);
  MultiDimVal.Nodes.push_back(node);
}

MultiVariateIntegrator::NodesAndWeights ProductIntegrator::getNodesAndWeights(int N_l, int d) const {
  const NumericalIntegrator::NodesAndWeights OneDimVal = UniVariateIntegrator.getNodesAndWeights(N_l);
  MultiVariateIntegrator::NodesAndWeights MultiDimVal(pow(N_l, d));
  std::vector<int> k(d, 1);

  do {
    genMultiWeightAndNode(OneDimVal, MultiDimVal, d, k);
  } while (incrementIndex(k, N_l, d));

  return MultiDimVal;
}
