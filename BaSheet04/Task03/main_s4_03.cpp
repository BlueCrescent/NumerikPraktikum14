/*
 * main_s4_03.cpp
 *
 *  Created on: Jun 20, 2014
 *      Author: boris
 */

#include <fstream>

#include "closedFormSolutions.h"


void main_s4_03() {
  const double S0 = 10.;
  const double K = 10.;
  const double T = 1.;
  const double r = 0.05;
  const double sigma = 0.2;
  std::ofstream out;
  out.open("data_s4_03");
  for (double B = 0.; B < 10.; B += 0.1) {
    out << B << " " << computeDownOutCallClosedForm(S0, r, sigma, T, K, B) << std::endl;
  }
  out.close();
}
