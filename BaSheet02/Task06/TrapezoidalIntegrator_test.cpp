/*
 * TrapezoidalIntegrator_test.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "TrapezoidalIntegrator.h"

#include "gtest/gtest.h"

class TrapezoidalIntegratorTest : public ::testing::Test {
public:

  TrapezoidalIntegrator integrator;
};

TEST_F(TrapezoidalIntegratorTest, PolynomialIntegrationExactnessTestsDegree1) {
  ASSERT_DOUBLE_EQ(0.5, integrator.integrate(2, [](double x){return x;}));
}

double piecewise_linear(double x) {
//  x += 1. / 8.;
//  if (x <= 0.)
//    return 0.;
  if (x <= 1. / 8.)
    return 8 * x;
  if (x <= 2. / 8.)
    return 1.;
  if (x <= 3. / 8.)
    return 8. * x - 1.;
  if (x <= 4. / 8.)
    return - 8. * x + 5.;
  if (x <= 5. / 8.)
    return 1.;
  if (x <= 6. / 8.)
    return - 8. * x + 6.;
  else
    return 0.;
}

TEST_F(TrapezoidalIntegratorTest, PiecewiseLinearTest) {
  ASSERT_DOUBLE_EQ(3. / 4., integrator.integrate(3, piecewise_linear));
}
