/*
 * CDFNormalDice_test.cpp
 *
 *  Created on: 18.04.2014
 *      Author: timm
 */

#include "CDFNormalDice.h"
#include "Cpp11UniformDice.h"
#include <cmath>

#include "gtest/gtest.h"

class CDFNormalTest : public ::testing::Test {
public:
  CDFNormalTest() :
    UnifDice(),
    NormalDice(UnifDice)
  {
  }

  Cpp11UniformDice UnifDice;
  CDFNormalDice NormalDice;
};

TEST_F(CDFNormalTest, NormalCDFInverseForOneHalf) {
  ASSERT_DOUBLE_EQ(0., NormalDice.NormalCDFInverse(0.5));
}

TEST_F(CDFNormalTest, NormalCDFInverseIsStrictlyIncreasing) {
  const unsigned int n = 10000;
  for (unsigned int i = 0; i < n; ++i)
    ASSERT_LT(NormalDice.NormalCDFInverse(i / ((double) n)),
              NormalDice.NormalCDFInverse((i + 1) / ((double) n)));
}

TEST_F(CDFNormalTest, RunRoll) {
  NormalDice.roll();
}
