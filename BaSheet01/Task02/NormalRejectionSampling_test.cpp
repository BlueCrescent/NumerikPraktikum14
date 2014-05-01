/*
 * NormalRejectionSampling_test.cpp
 *
 *  Created on: 10.04.2014
 *      Author: boris
 */

#include "NormalRejectionSampling.h"
#include "GSLUniformDice.h"
#include <cmath>

#include "gtest/gtest.h"

class RejectionSamplingTest : public ::testing::Test {
public:
  RejectionSamplingTest() :
    UnifDice(),
    NormalDice(UnifDice)
  {
  }

  GSLUniformDice UnifDice;
  NormalRejectionSampling NormalDice;
};

TEST_F(RejectionSamplingTest, NormalDensityFor0) {
  ASSERT_DOUBLE_EQ(NormalRejectionSampling::MaxNormalDensity,
                   NormalDice.NormalDensity(0.));
}

TEST_F(RejectionSamplingTest, NormalDensityFor1) {
  ASSERT_DOUBLE_EQ(NormalRejectionSampling::MaxNormalDensity / sqrt(exp(1.)) ,
                   NormalDice.NormalDensity(1));
}

TEST_F(RejectionSamplingTest, RunRoll) {
  NormalDice.roll();
}
