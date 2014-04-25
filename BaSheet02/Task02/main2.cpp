/*
 * main2.cpp
 *
 *  Created on: 25.04.2014
 *      Author: BlueCrescent
 */

#include <fstream>

#include "SimulateSDE.h"
#include "sample_path_simulation.h"

void print_results(const double dellts_ts[], const double mean_estimates[],
                   const double var_estimates[], unsigned int size);

void main_s2_02() {
  const unsigned int num_test_runs = 4;

  const unsigned int simulation_size = 1000;

  const double sigma = 0.2;
  const double mu = 0.1;
  const double start_value = 10.;
  const double test_delta_ts[num_test_runs] = {0.2, 0.8, 1., 2.};
  unsigned int strike = 10;

  double mean_estimates[num_test_runs];
  double var_estimates[num_test_runs];

  for (unsigned int i = 0; i < num_test_runs; ++i) {
    SDEParameter params = {start_value, mu, sigma, test_delta_ts[i]};
    const OnlineEstimator estimation = SDEsimulation_estimates(simulation_size, strike, params);
    mean_estimates[i] = estimation.get_current_mean();
    var_estimates[i] = estimation.get_current_variance();
  }

  print_results(test_delta_ts, mean_estimates, var_estimates, num_test_runs);
}

void create_file_2_2(std::ofstream & out_file) {
  out_file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  out_file.open("data_sh2_2", std::ofstream::trunc);
}

void print_results(const double dellts_ts[], const double mean_estimates[],
                   const double var_estimates[], const unsigned int size) {
  std::ofstream out_file;
  create_file_2_2(out_file);
  for (unsigned int i = 0; i < size; ++i)
    out_file << dellts_ts[i] << " " << mean_estimates[i] << " " << var_estimates[i] << std::endl;
  out_file.close();
}
