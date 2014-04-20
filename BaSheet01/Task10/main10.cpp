/*
 * main10.cpp
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#include "SimulateSDE.h"

#include "Cpp11NormalDice.h"

#include <fstream>
#include <sstream>
#include <iostream>

void simulate_and_print_SDEs(double T, double mu, double sigma, double start_value, double delta_t);

int main10() {
  const double T = 2.;
  const double mu = 0.1, sigma = 0.2;
  const double start_value = 10.;
  std::cout << "  Running with T = " << T << ", mu = " << mu << ", sigma = " << sigma
            << "and start value " << start_value << "..." << std::endl;

  const double delta_t1 = 0.5;
  std::cout << "   ... delta t = " << delta_t1 << "..." << std::endl;
  simulate_and_print_SDEs(T, mu, sigma, start_value, delta_t1);

  const double delta_t2 = 0.01;
  std::cout << "   ... delta t = " << delta_t2 << "..." << std::endl;
  simulate_and_print_SDEs(T, mu, sigma, start_value, delta_t2);

  return 0;
}

const void create_files(const double delta_t, std::ofstream & sde_file, std::ofstream & wiener_file, const int nr) {
  sde_file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  std::stringstream filename_wiener;
  filename_wiener << "data10_wiener_" << delta_t << "_nr" << nr;
  sde_file.open(filename_wiener.str(), std::ofstream::trunc);

  wiener_file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  std::stringstream filename_sde;
  filename_sde << "data10_sde_" << delta_t << "_nr" << nr;
  wiener_file.open(filename_sde.str(), std::ofstream::trunc);
}

void simulate_and_print_SDEs(double T, double mu, double sigma, double start_value, double delta_t) {
  Cpp11NormalDice normal_dice;
  for (unsigned int i = 1 ; i <= 3; ++i) {
    std::ofstream sde_file;
    std::ofstream wiener_file;
    create_files(delta_t, sde_file, wiener_file, i);

    SDE sde(start_value, mu, sigma, delta_t, normal_dice);
    for (; sde.get_current_time() <= T; sde.next_step()) {
      sde_file << sde.get_current_time() << " " << sde.compute_current_value() << std::endl;
      wiener_file << sde.get_current_time() << " " << sde.get_current_wiener_value() << std::endl;
    }

    sde_file.close();
    wiener_file.close();
  }
}
