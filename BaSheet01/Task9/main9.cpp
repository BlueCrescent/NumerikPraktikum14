/*
 * main9.cpp
 *
 *  Created on: 19.04.2014
 *      Author: BlueCrescent
 */

#include "Cpp11NormalDice.h"

#include "convergence_plot_data.h"

int main9() {
  Cpp11NormalDice dice;
  const unsigned int numSamples = 1e4;
  const double mu = 2;

  const double sigma1 = 0.1;
  generate_convergence_data_with(mu, sigma1, numSamples, dice);

  const double sigma2 = 1.;
  generate_convergence_data_with(mu, sigma2, numSamples, dice);

  const double sigma3 = 10.;
  generate_convergence_data_with(mu, sigma3, numSamples, dice);

  return 0;
}





