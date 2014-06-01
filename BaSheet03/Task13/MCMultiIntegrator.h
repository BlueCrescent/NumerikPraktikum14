/*
 * MCMultiIntegrator.h
 *
 *  Created on: 28.05.2014
 *      Author: timm
 */

#ifndef MCMULTIINTEGRATOR_H_
#define MCMULTIINTEGRATOR_H_

#include "MultiVariateIntegrator.h"
#include "IUniformDist.h"

#include <cmath>

class MCMultiIntegrator: public MultiVariateIntegrator {
public:
  MCMultiIntegrator(IUniformDist & dice);

  template<typename T>
  double integrate_efficient(int level, int d, T function) const;

  NodesAndWeights getNodesAndWeights(int l, int d) const;

private:
  IUniformDist & dice;

  std::vector<double> generateRandomNode(const int d) const;
};

template<typename T>
double MCMultiIntegrator::integrate_efficient(int level, int d, T function) const{
  const int N_l = pow(pow(2, level) - 1,d);

  double result = 0;
  for(int i = 0; i < N_l; ++i){
    result += function(generateRandomNode(d)) / N_l;
  }
  return result;
}

#endif /* MCMULTIINTEGRATOR_H_ */
