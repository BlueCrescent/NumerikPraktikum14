/*
 * main4.cpp
 *
 *  Created on: 09.05.2014
 *      Author: boris
 */

#include "asian_fair_prices.h"

#include <fstream>
#include <iomanip>
#include <cmath>

inline void generateGeometricDiscreteContinuousRelError(const unsigned int MAX_L, const char * filename);

void main_s3_04() {
  const unsigned int MAX_L = 10;

  generateGeometricDiscreteContinuousRelError(MAX_L, "data_s3_04");
}

void functionKernel(const unsigned int MAX_L, std::ofstream& myfile) {
  const double start_value = 10, r = 0.1, sigma = 0.25, strike = 10., strike_time = 1.;

  const double cont_val = calc_continious_geometric_fairP(start_value, r, sigma, strike, strike_time);

  for (unsigned int l = 0; l <= MAX_L; ++l) {
    const int M = pow(2, l);
    const double discr_val = calc_discrete_geometric_fairP(start_value, r, sigma, strike, strike_time, M);
    myfile << M << " " << fabs(discr_val - cont_val) / cont_val << std::endl;
  }
}

void generateGeometricDiscreteContinuousRelError(const unsigned int MAX_L, const char * filename) {
  std::ofstream myfile;
  myfile.open(filename);
  myfile << std::setprecision(40);

  functionKernel(MAX_L, myfile);

  myfile.close();
}

