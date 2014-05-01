/*
 * main1.cpp
 *
 *  Created on: 25.04.2014
 *      Author: BlueCrescent
 */

#include <fstream>

#include "SimulateSDE.h"
#include "sample_path_simulation.h"

void print_results(const double sigmas[], const double mean_estimates[], unsigned int size);

void main_s2_01() {
  const unsigned int num_test_runs = 5;

  const unsigned int simulation_size = 1000;

  const double test_sigmas[num_test_runs] = {0., 0.2, 0.4, 0.6, 0.8};
  const double mu = 0.1;
  const double start_value = 10.;
  const double delta_t = 0.2;
  const double total_time = 2.;
  const double strike = 10;

  double mean_estimates[num_test_runs];

  for (unsigned int i = 0; i < num_test_runs; ++i) {
    SDEParameter params = {start_value, mu, test_sigmas[i], delta_t};
    mean_estimates[i] = SDEsimulation_estimates(simulation_size, strike, total_time, params).get_current_mean();
  }

  print_results(test_sigmas, mean_estimates, num_test_runs);
}

void create_file_2_1(std::ofstream & out_file) {
  out_file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  out_file.open("data_sh2_1", std::ofstream::trunc);
}

void print_results(const double sigmas[], const double mean_estimates[], const unsigned int size) {
  std::ofstream out_file;
  create_file_2_1(out_file);
  for (unsigned int i = 0; i < size; ++i)
    out_file << sigmas[i] << " " << mean_estimates[i] << std::endl;
  out_file.close();
}
