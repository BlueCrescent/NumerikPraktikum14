/*
 * sample_path_simulation.cpp
 *
 *  Created on: 25.04.2014
 *      Author: BlueCrescent
 */

#include "sample_path_simulation.h"

#include "Cpp11NormalDice.h"

void simulate_one_path(const SDEParameter params, const unsigned int strike,
                      Cpp11NormalDice & dice, OnlineEstimator & estimator) {
  SDE sample_path(params, dice);
  for (unsigned int j = 0; j < strike; ++j)
    sample_path.next_step();
  estimator.add_sample(sample_path.compute_current_value());
}

OnlineEstimator SDEsimulation_estimates(const unsigned int num_sims, const unsigned int strike,
                                        const SDEParameter params) {
  Cpp11NormalDice dice;
  OnlineEstimator estimator;
  for (unsigned int i = 0; i < num_sims; ++i) {
    simulate_one_path(params, strike, dice, estimator);
  }
  return estimator;
}
