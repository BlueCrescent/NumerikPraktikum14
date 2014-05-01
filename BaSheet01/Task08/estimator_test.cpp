/*
 * estimator_test.cpp
 *
 *  Created on: 18.04.2014
 *      Author: BlueCrescent
 */


#include "gtest/gtest.h"

#include <random>

#include "estimator.h"

inline void fill_with_gauss_values(double * values, const unsigned int size, const double mean, const double variance) {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mean, variance);
  for (unsigned int i = 0; i < size; ++i) {
    values[i] = distribution(generator);
  }
}

TEST(EstimatorTest, TestThatNaiveEstimatorAndOnlineEstimatorAreEqual) {
  const unsigned int size = 1000;
  double values[size];
  fill_with_gauss_values(values, size, 5., 2.);

  const double naive_var_estimator = naive_variance_estimator(values, size);
  const double online_var_estimator = variance_estimator(values, size);

  ASSERT_DOUBLE_EQ(naive_var_estimator, online_var_estimator);
}
