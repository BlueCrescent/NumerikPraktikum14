/*
 * NumericalIntegrator.h
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#ifndef NUMERICALINTEGRATOR_H_
#define NUMERICALINTEGRATOR_H_

#include <vector>

#include <cassert>
#include <cmath>

class NumericalIntegrator {
public:
  struct NodesAndWeights {

      std::vector<double> Weights;
      std::vector<double> Nodes;

      inline int getSize() const;
  };

  template<typename T>
  double integrate(int level, T function) const;

  virtual NodesAndWeights getNodesAndWeights(int amount) const = 0;

  virtual ~NumericalIntegrator(){};
};

inline int NumericalIntegrator::NodesAndWeights::getSize() const {
  assert(Weights.size() == Nodes.size());
  return Weights.size();
}

template<typename T>
double NumericalIntegrator::integrate(int level, T function) const{
  const int amount = pow(2,level) - 1;
  const NodesAndWeights Parameters = getNodesAndWeights(amount);

  double result = 0;
  for(int i = 0; i < Parameters.getSize(); ++i){
    result += function(Parameters.Nodes[i]) * Parameters.Weights[i];
  }
  return result;
}



#endif /* NUMERICALINTEGRATOR_H_ */
