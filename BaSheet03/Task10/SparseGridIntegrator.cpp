/*
 * SparseGridIntegrator.cpp
 *
 *  Created on: 21.05.2014
 *      Author: boris
 */

#include "SparseGridIntegrator.h"

#include <vector>
#include <utility>
#include <cmath>
#include <cassert>

typedef SparseGridIntegrator::NodesAndWeights NodesAndWeights;
typedef NumericalIntegrator::NodesAndWeights NodesAndWeights1D;

SparseGridIntegrator::SparseGridIntegrator(const HierarchicalIntegrator & _univariateIntegrator) :
  UniVariateIntegrator(_univariateIntegrator)
{
}

std::vector<NodesAndWeights1D> SparseGridIntegrator::generateOneDimValues(int l) const {
  std::vector<NodesAndWeights1D> OneDimVals;
  OneDimVals.push_back(NodesAndWeights1D());
  for (int k = 1; k <= l; ++k)
    OneDimVals.push_back(UniVariateIntegrator.iterateLevel(OneDimVals[k - 1]));
  return OneDimVals;
}

inline bool incrementMaxIndex(std::vector<int> & kMax, int & sumK, const int l, const int d) {
  for (int j = 0; j < d; ++j) {
    kMax[j]++;
    sumK++;
    if (sumK > d + l - 1) {
      if (j == d - 1)
        return false;
      sumK -= kMax[j] - 1;
      kMax[j] = 1;
    } else
      break;
  }

  return true;
}

inline bool incrementIndex(std::vector<int> & k, const std::vector<int> & kMax, int d) {
  for (int j = 0; j < d; ++j) {
    k[j]++;
    if (k[j] > pow(2, kMax[j]) - 1) {
      if (j == d - 1)
        return false;

      k[j] = 1;
    } else
      break;
  }
  return true;
}

inline void genMultiWeightAndNodeKernel(const std::vector<NodesAndWeights1D> OneDimVals,
                                        NodesAndWeights & MultiDimVal,
                                        int d, const std::vector<int> & k,
                                        const std::vector<int> & kMax) {
  std::vector<double> node;
  node.reserve(d);
  double weight = 1;

  for(int j = 0; j < d; ++j) {
    assert(0 <= k[j] - 1 && k[j] - 1 < OneDimVals[kMax[j]].getSize());
    if (k[j] % 2 == 0)
      weight *= OneDimVals[kMax[j]].Weights[k[j] - 1] -
                OneDimVals[kMax[j] - 1].Weights[k[j] / 2 - 1];
    else
      weight *= OneDimVals[kMax[j]].Weights[k[j] - 1];
    node.push_back(OneDimVals[kMax[j]].Nodes[k[j] - 1]);
  }

  MultiDimVal.Weights.push_back(weight);
  MultiDimVal.Nodes.push_back(node);
}

inline void genMultiWeightAndNode(const std::vector<NodesAndWeights1D> OneDimVals,
                                  NodesAndWeights & MultiDimVal,
                                  int d, std::vector<int> & kMax) {
  std::vector<int> k(d, 1);
  do {
    genMultiWeightAndNodeKernel(OneDimVals, MultiDimVal, d, k, kMax);
  } while (incrementIndex(k, kMax, d));
}

NodesAndWeights SparseGridIntegrator::getNodesAndWeights(int l, int d) const {
  const int N_l = pow(2, l) - 1;
  const std::vector<NodesAndWeights1D> OneDimVals = generateOneDimValues(l); // FIXME Use move semantic here.
  NodesAndWeights MultiDimVal; // FIXME With required size.

  std::vector<int> kMax(d, 1);
  int sumK = d;

  do {
    genMultiWeightAndNode(OneDimVals, MultiDimVal, d, kMax);
  } while (incrementMaxIndex(kMax, sumK, N_l, d));

  return MultiDimVal;
}
