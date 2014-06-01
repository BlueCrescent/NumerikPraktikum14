/*
 * QMCMultiIntegrator.h
 *
 *  Created on: 28.05.2014
 *      Author: BlueCrescent
 */

#ifndef QMCMULTIINTEGRATOR_H_
#define QMCMULTIINTEGRATOR_H_

#include "MultiVariateIntegrator.h"
#include "HaltonSequence.h"

#include <utility>

class QMCMultiIntegrator: public MultiVariateIntegrator {
public:
  NodesAndWeights getNodesAndWeights(int l, int d) const;

  template<typename T>
  double integrate_efficient(int level, int d, T function) const;
};

template<typename T>
double QMCMultiIntegrator::integrate_efficient(int level, int d, T function) const{
  const int N_l = pow(pow(2, level) - 1,d);
  std::vector<double> haltonPoint = generateFirstPoint(d);

  double result = 0;
  for(int i = 0; i < N_l; ++i) {
    result += function(haltonPoint) / N_l;
    haltonPoint = std::move(generateNextHaltonValue(haltonPoint));
  }
  return result;
}

#endif /* QMCMULTIINTEGRATOR_H_ */
