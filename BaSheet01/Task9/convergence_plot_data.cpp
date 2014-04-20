/*
 * convergence_plot_data.cpp
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#include "convergence_plot_data.h"

#include "estimator.h"
#include <sstream>

inline void generateData(double * values, const unsigned int size,
                         const double mu, const double sigma, INormalDistribution& dice) {
  for (unsigned int i = 0; i < size; ++i)
    values[i] = mu + sigma * dice.roll();
}

const void createFile(const double sigma, std::ofstream & dataFile) {
//  std::string filename = std::string("data9_") + std::to_string(sigma);
  std::stringstream filename;
  filename << "data9_" << sigma;
  dataFile.open(filename.str(), std::ofstream::trunc);
}

void generate_convergence_data_with(const double mu, const double sigma, const unsigned int size, INormalDistribution & dice) {
  double values[size];
  generateData(values, size, mu, sigma, dice);
  std::ofstream dataFile;
  createFile(sigma, dataFile);

  stream_variance_estimator_error(values, size, sigma, dataFile);

  dataFile.close();
}

