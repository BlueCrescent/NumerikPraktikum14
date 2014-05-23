/*
 * main_s3_12.cpp
 *
 *  Created on: 22.05.2014
 *      Author: BlueCrescent
 */

#include "SparseGridIntegrator.h"
#include "NumericalIntegrator.h"
#include "TrapezoidalIntegrator.h"

#include <fstream>
#include <iomanip>

#include <cmath>

int getSparsePointAmount(int l, int d) {
  const TrapezoidalIntegrator univIntegrator;
  const SparseGridIntegrator multivariateIntegrator(univIntegrator);
  return multivariateIntegrator.getNodesAndWeights(l, d).getSize();
}

void printPointAmounts(int l, const char * filename) {
  std::ofstream file;
  file.open(filename);
  file << std::setprecision(40);

  for (int d = 1; d <= 10; ++d) {
    file << d << " " << pow(pow(2, l) - 1, d) << " " << getSparsePointAmount(l, d) << std::endl;
  }

  file.close();
}

void main_s3_12() {
  const int l = 4;

  printPointAmounts(l, "data_sh3_12_num_of_nodes");
}


