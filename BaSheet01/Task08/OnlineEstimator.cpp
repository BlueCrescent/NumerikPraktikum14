/*
 * OnlineEstimator.cpp
 *
 *  Created on: 23.04.2014
 *      Author: BlueCrescent
 */

#include "OnlineEstimator.h"

OnlineEstimator::OnlineEstimator() :
  sample_count(0),
  mean(0.),
  variance_sum(0.)
{
}

void OnlineEstimator::add_sample(const double value) {
  variance_estimation_step(value);
  ++sample_count;
}

inline void OnlineEstimator::variance_estimation_step(const double value) {
  const double gamma = value - mean;
  mean = mean + gamma / (sample_count + 1);
  variance_sum = variance_sum + gamma * gamma * sample_count / (sample_count + 1);
}
