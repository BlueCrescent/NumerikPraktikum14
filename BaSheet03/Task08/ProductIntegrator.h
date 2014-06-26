/*
 * ProductIntegrator.h
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#ifndef PRODUCTINTEGRATOR_H_
#define PRODUCTINTEGRATOR_H_

#include <vector>
#include <cmath>

#include "MultiVariateIntegrator.h"
#include "NumericalIntegrator.h"

class ProductIntegrator : public MultiVariateIntegrator {
public:
  ProductIntegrator(const NumericalIntegrator& UniVariateIntegrator);

  NodesAndWeights getNodesAndWeights(int l, int d) const;

  template<typename T>
  double integrateEfficient(int level, int d, T function) const;

private:
  std::pair<std::vector<double>,double> genMultiWeightAndNode(const NumericalIntegrator::NodesAndWeights & OneDimVal,
                                    int d, const std::vector<int> & k) const;
  bool incrementIndex(std::vector<int>& k, int N_l, int d) const;
  const NumericalIntegrator& UniVariateIntegrator;
};

template<typename T>
inline double ProductIntegrator::integrateEfficient(int level, int d, T function) const {
  const int N_l = pow(2, level) - 1;
  const NumericalIntegrator::NodesAndWeights OneDimVal = UniVariateIntegrator.getNodesAndWeights(N_l);
  double result = 0;
  std::vector<int> k(d, 1);

  do {
    std::pair<std::vector<double>,double> nodeAndWeight = std::move(genMultiWeightAndNode(OneDimVal, d, k));
    result += function(nodeAndWeight.first) * nodeAndWeight.second;
  } while (incrementIndex(k, N_l, d));
  return result;
}

#endif /* PRODUCTINTEGRATOR_H_ */
