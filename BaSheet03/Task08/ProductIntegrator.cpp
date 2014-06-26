/*
 * ProductIntegrator.cpp
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#include "ProductIntegrator.h"
#include <utility>

#include <cassert>

ProductIntegrator::ProductIntegrator(const NumericalIntegrator& _UniVariateIntegrator) :
    UniVariateIntegrator(_UniVariateIntegrator)
{
}

bool ProductIntegrator::incrementIndex(std::vector<int>& k, int N_l, int d) const {
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

std::pair<std::vector<double>,double> ProductIntegrator::genMultiWeightAndNode(const NumericalIntegrator::NodesAndWeights & OneDimVal,
                                  int d, const std::vector<int> & k) const {
  std::vector<double> node;
  node.reserve(d);
  double weight = 1;

  for(int j = 0; j < d; ++j) {
    assert(0 <= k[j] - 1 && k[j] - 1 < OneDimVal.getSize());
    weight *= OneDimVal.Weights[k[j] - 1];
    node.push_back(OneDimVal.Nodes[k[j] - 1]);
  }
  return std::pair<std::vector<double>,double> (std::move(node), weight);
}

MultiVariateIntegrator::NodesAndWeights ProductIntegrator::getNodesAndWeights(int l, int d) const {
  const int N_l = pow(2, l) - 1;
  const NumericalIntegrator::NodesAndWeights OneDimVal = UniVariateIntegrator.getNodesAndWeights(N_l);
  MultiVariateIntegrator::NodesAndWeights MultiDimVal(pow(N_l, d));
  std::vector<int> k(d, 1);

  do {
    std::pair<std::vector<double>,double> nodeAndWeight = std::move(genMultiWeightAndNode(OneDimVal, d, k));
    MultiDimVal.Nodes.push_back(nodeAndWeight.first);
    MultiDimVal.Weights.push_back(nodeAndWeight.second);
  } while (incrementIndex(k, N_l, d));

  return MultiDimVal;
}
