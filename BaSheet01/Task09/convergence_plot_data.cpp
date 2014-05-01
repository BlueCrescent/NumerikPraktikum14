/*
 * convergence_plot_data.cpp
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#include "convergence_plot_data.h"

#include "estimator.h"
#include <sstream>
#include <fstream>

const void create_file(const double sigma, std::ofstream & dataFile) {
  dataFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  std::stringstream filename;
  filename << "data9_" << sigma;
  dataFile.open(filename.str(), std::ofstream::trunc);
}

void generate_convergence_data_with(const double mu, const double sigma, long long unsigned int size, INormalDistribution & dice) {
  ++size;
  std::ofstream dataFile;
  create_file(sigma, dataFile);

  stream_variance_estimator_error(dice, size, mu, sigma, dataFile);

  dataFile.close();
}

