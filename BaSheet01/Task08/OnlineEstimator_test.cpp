/*
 * OnlineEstimator_test.cpp
 *
 *  Created on: 23.04.2014
 *      Author: BlueCrescent
 */

#include "OnlineEstimator.h"

#include "gtest/gtest.h"

class OnlineEstimatorTest : public ::testing::Test {
public:
  OnlineEstimator estimator;
};

TEST_F(OnlineEstimatorTest, AddingSampleIncreasesSampleCount) {
  estimator.add_sample(10.);

  ASSERT_DOUBLE_EQ(estimator.get_sample_count(), 1);
}

TEST_F(OnlineEstimatorTest, WhenGivenOneValue_ThisIsTheMeanAndVarianceIsZero) {
  estimator.add_sample(10.);

  ASSERT_DOUBLE_EQ(estimator.get_current_mean(), 10.);
  ASSERT_DOUBLE_EQ(estimator.get_current_variance(), 0.);
}

TEST_F(OnlineEstimatorTest, WhenGivenSomeIdenticalValues_ThisIsTheMeanAndVarianceIsZero) {
  estimator.add_sample(10.);
  estimator.add_sample(10.);
  estimator.add_sample(10.);
  estimator.add_sample(10.);

  ASSERT_DOUBLE_EQ(estimator.get_current_mean(), 10.);
  ASSERT_DOUBLE_EQ(estimator.get_current_variance(), 0.);
}

TEST_F(OnlineEstimatorTest, GivenValues_10_20_MeanIs_15_VarianceIs_50) {
  estimator.add_sample(10.);
  estimator.add_sample(20.);

  ASSERT_DOUBLE_EQ(estimator.get_current_mean(), 15.);
  ASSERT_DOUBLE_EQ(estimator.get_current_variance(), 50.);
}

#include <random>
#include "estimator.h"

inline void fill_with_gauss_values(double * values, const unsigned int size, const double mean, const double variance) {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mean, variance);
  for (unsigned int i = 0; i < size; ++i)
    values[i] = distribution(generator);
}

TEST_F(OnlineEstimatorTest, TestIfVarianceIsEqualToNaiveImplementation) {
  const unsigned int size = 1000;
  double values[size];
  fill_with_gauss_values(values, size, 5., 2.);

  for (unsigned int i = 0; i < size; ++i)
    estimator.add_sample(values[i]);

  const double naive_var_estimator = naive_variance_estimator(values, size);
  const double online_var_estimator = estimator.get_current_variance();

  ASSERT_DOUBLE_EQ(naive_var_estimator, online_var_estimator);
}
