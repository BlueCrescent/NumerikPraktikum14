///*
// * BoxMullerDice_test.cpp
// *
// *  Created on: 18.04.2014
// *      Author: boris
// */

#include "BoxMullerDice.h"
#include "gtest/gtest.h"
#include "Cpp11UniformDice.h"


class BoxMullerDiceTest : public ::testing::Test {
public:
  BoxMullerDiceTest() :
    UnifDice(),
    BMNormalDice(UnifDice)
  {
  }

  Cpp11UniformDice UnifDice;
  BoxMullerDice BMNormalDice;
};

TEST_F(BoxMullerDiceTest, Testroll){
  BMNormalDice.roll();
  BMNormalDice.rollPair();
}

