/*
 * estimator.cpp
 *
 *  Created on: 18.04.2014
 *      Author: BlueCrescent
 */

#include <algorithm>

inline double estimate_mean(const double* values, const unsigned int size) {
  double mean_estimate = 0;
  std::for_each(values, values + size,
                [&](double val) {mean_estimate += val;});
  return mean_estimate / size;
}

inline double estimate_variance(const double* values, const unsigned int size, const double mean) {
  double variance_estimate = 0;
  std::for_each(values, values + size,
                [&](double val) {variance_estimate += (val - mean) * (val - mean);});
  return variance_estimate / (size - 1);
}

double naive_variance_estimator(const double * values, const unsigned int size) {
  const double mean_estimate = estimate_mean(values, size);
  return estimate_variance(values, size, mean_estimate);
}

double variance_estimator(const double * values, const unsigned int size) {
  double alpha = values[0];
  double beta = 0;
  for (unsigned int i = 1; i < size; ++i) {
    const double gamma = values[i] - alpha;
    alpha = alpha + gamma / (i + 1);
    beta = beta + gamma * gamma * i / (i + 1);
  }
  return beta / (size - 1);
}

