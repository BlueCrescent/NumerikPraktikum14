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

class NumericalIntegrator {
public:
  class NodesAndWeights {
    public:
      std::vector<double> Weights;
      std::vector<double> Nodes;

      inline int getSize() const{
        assert(Weights.size() == Nodes.size());
        return Weights.size();
      }
    };

  template<typename T>
  double integrate(int level, T function) const;

  virtual NodesAndWeights getNodesAndWeights(int amount) const = 0;

  virtual ~NumericalIntegrator(){};
};



#endif /* NUMERICALINTEGRATOR_H_ */
