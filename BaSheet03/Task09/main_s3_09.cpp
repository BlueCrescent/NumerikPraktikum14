/*
 * main_s3_07.cpp
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#include "ProductIntegrator.h"
#include "NumericalIntegrator.h"
#include "TrapezoidalIntegrator.h"
#include "GaussLegendreIntegrator.h"
#include "ClenshawIntegrator.h"

#include <vector>
#include <fstream>
#include <iomanip>
#include <utility>

#include <cmath>

void computeAndPrint(const int l, std::ostream& output, const ProductIntegrator& integrator) {
  const int N_l = pow(2, l) - 1;
  const std::vector<std::vector<double> > nodes(std::move(integrator.getNodesAndWeights(N_l, 2).Nodes));
//  const MultiVariateIntegrator::NodesAndWeights nW = integrator.getNodesAndWeights(N_l, 2);
//  const std::vector<std::vector<double> > nodes(integrator.getNodesAndWeights(N_l, 2).Nodes);
  for (unsigned int i = 0; i < nodes.size(); ++i) {
    output << nodes[i][0] << " " << nodes[i][1] << std::endl;
  }
}

void print2DimProductRuleNodes(const NumericalIntegrator & univariateIntegrator, const char * filename, const int l) {
  std::ofstream file;
  file.open(filename);
  file << std::setprecision(40);

  const ProductIntegrator multivariateIntegrator(univariateIntegrator);
  computeAndPrint(l, file, multivariateIntegrator);

  file.close();
}

void main_s3_09() {
  const int l = 5;

  const TrapezoidalIntegrator trapIntegrator;
  print2DimProductRuleNodes(trapIntegrator, "data_sh3_09_trapezoidal", l);

  const GaussLegendreIntegrator gaussIntegrator;
  print2DimProductRuleNodes(gaussIntegrator, "data_sh3_09_gaussLegendre", l);

  const ClenshawIntegrator clencurIntegrator;
  print2DimProductRuleNodes(clencurIntegrator, "data_sh3_09_clenshawCurtis", l);
}


