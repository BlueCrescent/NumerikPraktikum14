/*
 * MultiVariateIntegrator.h
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#ifndef MULTIVARIATEINTEGRATOR_H_
#define MULTIVARIATEINTEGRATOR_H_

#include <cassert>
#include <vector>
#include <cmath>

class MultiVariateIntegrator {
public:
  struct NodesAndWeights {

      std::vector<double> Weights;
      std::vector<std::vector<double>> Nodes;

      NodesAndWeights(int reserveSize);

      inline int getSize() const;
  };

  template<typename T>
  double integrate(int level, int d, T function) const;

  virtual NodesAndWeights getNodesAndWeights(int N_l, int d) const = 0;

  virtual ~MultiVariateIntegrator(){}
};

inline MultiVariateIntegrator::NodesAndWeights::NodesAndWeights(int reserveSize) {
  Weights.reserve(reserveSize);
  Nodes.reserve(reserveSize);
}

inline int MultiVariateIntegrator::NodesAndWeights::getSize() const {
  assert(Weights.size() == Nodes.size());
  return Weights.size();
}

template<typename T>
double MultiVariateIntegrator::integrate(int level, int d, T function) const{
  const int N_l = pow(2,level) - 1;
  const NodesAndWeights Parameters = getNodesAndWeights(N_l, d);

  double result = 0;
  for(int i = 0; i < Parameters.getSize(); ++i){
    result += function(Parameters.Nodes[i]) * Parameters.Weights[i];
  }
  return result;
}

#endif /* MULTIVARIATEINTEGRATOR_H_ */
