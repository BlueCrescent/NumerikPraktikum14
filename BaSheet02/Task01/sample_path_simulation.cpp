/*
 * sample_path_simulation.cpp
 *
 *  Created on: 25.04.2014
 *      Author: BlueCrescent
 */

#include "sample_path_simulation.h"

#include "Cpp11NormalDice.h"

#include "option_values.h"

inline void simulate_one_path(const geometricBMParameter params, const double strike, const double time,
                              Cpp11NormalDice & dice, OnlineEstimator & estimator) {
  geometricBM sample_path(params, dice);
  while (sample_path.get_current_time() <= time)
    sample_path.next_step();
  estimator.add_sample(call_option_value(sample_path.compute_current_value(), strike));
}

OnlineEstimator SDEsimulation_estimates(const unsigned int num_sims, const double strike,
                                        const double time, const geometricBMParameter params) {
  Cpp11NormalDice dice;
  OnlineEstimator estimator;
  for (unsigned int i = 0; i < num_sims; ++i) {
    simulate_one_path(params, strike, time, dice, estimator);
  }
  return estimator;
}
