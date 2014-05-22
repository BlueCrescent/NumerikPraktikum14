/*
 * main_s3_11.cpp
 *
 *  Created on: 22.05.2014
 *      Author: BlueCrescent
 */

#include "SparseGridIntegrator.h"
#include "NumericalIntegrator.h"
#include "TrapezoidalIntegrator.h"
#include "ClenshawIntegrator.h"

#include <vector>
#include <fstream>
#include <iomanip>
#include <utility>

#include <cmath>

void computeAndPrint(const int l, std::ostream& output, const SparseGridIntegrator& integrator) {
  const std::vector<std::vector<double> > nodes(std::move(integrator.getNodesAndWeights(l, 2).Nodes));
  for (unsigned int i = 0; i < nodes.size(); ++i) {
    output << nodes[i][0] << " " << nodes[i][1] << std::endl;
  }
}

void print2DimProductRuleNodes(const HierarchicalIntegrator & univariateIntegrator, const char * filename, const int l) {
  std::ofstream file;
  file.open(filename);
  file << std::setprecision(40);

  const SparseGridIntegrator multivariateIntegrator(univariateIntegrator);
  computeAndPrint(l, file, multivariateIntegrator);

  file.close();
}

void main_s3_11() {
  const int l1 = 5, l2 = 7;

  const TrapezoidalIntegrator trapIntegrator;
  const ClenshawIntegrator clencurIntegrator;

  print2DimProductRuleNodes(trapIntegrator, "data_sh3_11_trapezoidal_l=5", l1);
  print2DimProductRuleNodes(clencurIntegrator, "data_sh3_11_clenshawCurtis_l=5", l1);

  print2DimProductRuleNodes(trapIntegrator, "data_sh3_11_trapezoidal_l=7", l2);
  print2DimProductRuleNodes(clencurIntegrator, "data_sh3_11_clenshawCurtis_l=7", l2);
}


