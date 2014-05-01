/*
 * GaussLegendreIntegrator.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "GaussLegendreIntegrator.h"

#include <gsl/gsl_integration.h>

struct GSLGaussLegendreWrapper {
  gsl_integration_glfixed_table * table;

  GSLGaussLegendreWrapper(int amount) :
    table(gsl_integration_glfixed_table_alloc(amount))
  {
  }

  ~GSLGaussLegendreWrapper() {
    gsl_integration_glfixed_table_free(table);
  }
};

inline void generateParameters(int amount, const GSLGaussLegendreWrapper& gl,
    NumericalIntegrator::NodesAndWeights& returnParam) {
  for (int i = 0; i < amount; ++i) {
    double xi, wi;
    gsl_integration_glfixed_point(0., 1., i, &xi, &wi, gl.table);
    returnParam.Nodes.push_back(xi);
    returnParam.Weights.push_back(wi);
  }
}

GaussLegendreIntegrator::NodesAndWeights
GaussLegendreIntegrator::getNodesAndWeights(int amount) const {
  GSLGaussLegendreWrapper gl(amount);
  NodesAndWeights returnParam;
  generateParameters(amount, gl, returnParam);
  return returnParam;
}
