/*
 * main4.cpp
 *
 *  Created on: 26.04.2014
 *      Author: BlueCrescent
 */


#include <fstream>
#include <sstream>

#include "SimulateSDE.h"
#include "Cpp11NormalDice.h"

#include "option_values.h"

void run_and_print_results(SDEParameter params, double time, double strike, unsigned int run);

void main_s2_04() {
  const unsigned int num_test_runs = 5;

  const double sigma = 0.2;
  const double mu = 0.1;
  const double start_value = 10.;
  const double delta_t = 1.;
  const double total_time = 1.;
  const double strike = 10;

  const SDEParameter params = {start_value, mu, sigma, delta_t};

  for (unsigned int i = 1; i <= num_test_runs; ++i) {
    run_and_print_results(params, total_time, strike, i);
  }
}

void create_file_2_4(std::ofstream & out_file, const unsigned int run) {
  out_file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  std::stringstream filename;
  filename << "data_sh2_4_run" << run;
  out_file.open(filename.str(), std::ofstream::trunc);
}

inline double call_value_of_sim_SDE(const SDEParameter params, const double time,
                                    const double strike, Cpp11NormalDice & dice) {
  SDE sample_path(params, dice);
  while (sample_path.get_current_time() <= time)
    sample_path.next_step();
  return call_option_value(sample_path.compute_current_value(), strike);
}

void run_and_print_results(const SDEParameter params, const double time,
                           const double strike, const unsigned int run) {
  std::ofstream out_file;
  create_file_2_4(out_file, run);
  Cpp11NormalDice dice;
  double sum = 0.;
  unsigned int j_start = 0, j_end = 1;
  for (unsigned int i = 0; i <= 6; ++i) {
    for (unsigned int j = j_start; j < j_end; ++j) {
      sum += call_value_of_sim_SDE(params, time, strike, dice);
    }
    out_file << j_end << " " << sum / j_end << std::endl;
    j_start = j_end;
    j_end *= 10;
  }
  out_file.close();
}

