/*
 * GaussLegendreIntegrator_test.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include "GaussLegendreIntegrator.h"

#include "gtest/gtest.h"

#include <cmath>

class GaussLegendreIntegrationTest : public ::testing::Test {
public:

  GaussLegendreIntegrator integrator;
};

TEST_F(GaussLegendreIntegrationTest, PolynomialIntegrationExactnessTestsDegree1) {
  ASSERT_DOUBLE_EQ(integrator.integrate(1, [](double x){return x;}), 0.5);
}

TEST_F(GaussLegendreIntegrationTest, PolynomialIntegrationExactnessTestsDegree5) {
  // 10*x^5 - 10*x^4 + 1.5*x^3 - (x - 0.5)^2 + 1
  ASSERT_DOUBLE_EQ(integrator.integrate(2, [](double x){return 10*x*x*x*x*x - 10*x*x*x*x + 1.5*x*x*x - (x - 0.5)*(x - 0.5) + 1;}),
                   0.958333333333333333333333333333);
}

double legendre_29(double x);

TEST_F(GaussLegendreIntegrationTest, PolynomialIntegrationExactnessTestsDegree29) {
  ASSERT_DOUBLE_EQ(integrator.integrate(4, legendre_29), 0.00498153269290924072265625);
}

double legendre_29(const double x) {
  return (1. / 33554432.) * (
    145422675. * x - 21037813650. * pow(x, 3) + 902522205585. * pow(x, 5) -
    18050444111700. * pow(x, 7) + 204070298707275. * pow(x, 9) - 1447043936287950. * pow(x, 11) +
    6845630929362225. * pow(x, 13) - 22427590854291480. * pow(x, 15) +
    51946258228689825. * pow(x, 17) - 85665759184155150. * pow(x, 19) +
    99943385714847675. * pow(x, 21) - 80586761604066900. * pow(x, 23) +
    42710983650155457. * pow(x, 25) - 13385208551330770. * pow(x, 27) +
    1879204156221315. * pow(x, 29));
}
