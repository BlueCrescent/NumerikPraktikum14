/*
 * estimator.cpp
 *
 *  Created on: 18.04.2014
 *      Author: BlueCrescent
 */

#include "estimator.h"

#include <algorithm>
#include <iostream>

#include <cmath>

inline double estimate_mean(const double* values, const unsigned int size) {
  double mean_estimate = 0;
  std::for_each(values, values + size,
                [&](const double val) {mean_estimate += val;});
  return mean_estimate / size;
}

inline double estimate_variance(const double* values, const unsigned int size, const double mean) {
  double variance_estimate = 0;
  std::for_each(values, values + size,
                [&](const double val) {variance_estimate += (val - mean) * (val - mean);});
  return variance_estimate / (size - 1);
}

double naive_variance_estimator(const double * values, const unsigned int size) {
  const double mean_estimate = estimate_mean(values, size);
  return estimate_variance(values, size, mean_estimate);
}


inline void variance_estimation_step(const double value, const long long unsigned int i, double & alpha, double & beta) {
  const double gamma = value - alpha;
  alpha = alpha + gamma / (i + 1);
  beta = beta + gamma * gamma * i / (i + 1);
}

double variance_estimator(const double * values, const unsigned int size) {
  double alpha = values[0];
  double beta = 0;
  for (unsigned int i = 1; i < size; ++i) {
    variance_estimation_step(values[i], i, alpha, beta);
  }
  return beta / (size - 1);
}

inline double estimation_error(const double sigma, const double beta, const long long unsigned int i) {
  if (beta == 0)
    return sigma;
  return fabs(sigma - sqrt(beta / i));
}

inline bool in_sample_interval(const long long unsigned int i, const unsigned int sample_interval) {
  return i % sample_interval == 0;
}

inline bool in_dynamic_sample_interval(const long long unsigned int i) {
  if (i < 10)
    return true;
  const unsigned int sample_interval = pow(10, static_cast<unsigned int>(log10(i)) - 1);
  return i % sample_interval == 0;
}

inline void stream_sample_ival_errors(const long long unsigned int i, const unsigned int sample_interval,
                                      const double sigma, const double sigma_est, std::ostream& out) {
  if (in_sample_interval(i, sample_interval))
    out << i << " " << estimation_error(sigma, sigma_est, i) << std::endl;
}

inline void stream_sample_ival_errors_dynamic(const long long unsigned int i, const double sigma,
                                              const double sigma_est, std::ostream& out) {
  if (in_dynamic_sample_interval(i))
    out << i + 1 << " " << estimation_error(sigma, sigma_est, i) << std::endl;
}

inline double roll_gauss(const double mu, const double sigma, INormalDistribution & dice) {
  return mu + sigma * dice.roll();
}

double stream_variance_estimator_error(INormalDistribution & dice, const long long unsigned int size,
                                       const  double mu, const double sigma, std::ostream & out) {
  double alpha = roll_gauss(mu, sigma, dice);
  double beta = 0;
  stream_sample_ival_errors_dynamic(0, sigma, beta, out);

  for (long long unsigned int i = 1; i < size; ++i) {
    const double value = roll_gauss(mu, sigma, dice);
    variance_estimation_step(value, i, alpha, beta);
    stream_sample_ival_errors_dynamic(i, sigma, beta, out);
  }

  return beta / (size - 1);
}

