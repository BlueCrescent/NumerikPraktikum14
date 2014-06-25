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
  long double integrate_efficient(int level, int d, T function) const;
};

template<typename T>
long double QMCMultiIntegrator::integrate_efficient(int level, int d, T function) const{
  const int N_l = pow(2, level) - 1;
  const double factor = 1. / N_l;
  std::vector<double> haltonPoint = generateFirstPoint(d);

  long double result = 0;
  for(int i = 0; i < N_l; ++i) {
    result += function(haltonPoint) * factor;
    haltonPoint = std::move(generateNextHaltonValue(haltonPoint));
//    haltonPoint = std::move(generateRandomNode(d));
  }
  return result;
}
//
//#if 0
//template<typename T>
//long double QMCMultiIntegrator::integrate_efficient(int level, int d, T function) const{
//  const int N_l = pow(2, level) - 1;
//  std::vector<double> haltonPoint = generateFirstPoint(d);
//
//  long double result = 0;
//  for (int run = 0; run < d; ++run) {
//    for(int i = 0; i < N_l; ++i) {
//      result += function(haltonPoint);
//      haltonPoint = std::move(generateNextHaltonValue(haltonPoint));
//    }
//  }
//  for (int run = 0; run < d; ++run) {
//    result /= N_l;
//  }
//  return result;
//}
//#endif

#endif /* QMCMULTIINTEGRATOR_H_ */
