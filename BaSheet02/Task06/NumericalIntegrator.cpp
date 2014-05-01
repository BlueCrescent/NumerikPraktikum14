/*
 * NumericalIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "NumericalIntegrator.h"
#include <cmath>

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

