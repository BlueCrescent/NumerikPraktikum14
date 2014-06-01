#include "TrapezoidalIntegrator.h"
#include "ClenshawIntegrator.h"
#include "ProductIntegrator.h"
#include "SparseGridIntegrator.h"
#include "MCMultiIntegrator.h"
#include "QMCMultiIntegrator.h"
#include "Cpp11UniformDice.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

double f(double x){
  return 1. + 0.1 * exp(x / 2.);
}

double multiF(const std::vector<double> & x){
  double val = 1;
  for(unsigned int j = 0; j < x.size(); ++j)
    val *= f(x[j]);
  return val;
}

double integrateF(int d){
  return pow(1. + 0.2 * exp(0.5) - 0.2, d);
}

double integrate(const MultiVariateIntegrator& tmp, const int level, const int d){
  return tmp.integrate(level, d, multiF);
}

void storeIntegrationPoints(std::ofstream& out, int d) {
  const TrapezoidalIntegrator TrapezRule;
  const ClenshawIntegrator ClenshawRule;
  const double exact = integrateF(d);
  Cpp11UniformDice Dice;
  for (int l = 1; l < 4; ++l) {
    out << l << " ";
    out << fabs(integrate(MCMultiIntegrator(Dice), l, d)            - exact ) / exact << " ";
    out << fabs(integrate(QMCMultiIntegrator(), l, d)               - exact ) / exact << " ";
    out << fabs(integrate(ProductIntegrator(TrapezRule), l, d)      - exact ) / exact << " ";
    out << fabs(integrate(ProductIntegrator(ClenshawRule), l, d)    - exact ) / exact << " ";
    out << fabs(integrate(SparseGridIntegrator(TrapezRule), l, d)   - exact ) / exact << " ";
    out << fabs(integrate(SparseGridIntegrator(ClenshawRule), l, d) - exact ) / exact << " ";
    out << std::endl;
  }
}

void main_s3_13(){
  for(int d = 1; d <= 8; d *= 2){
    std::ofstream out;
    out.open("data_s3_13_d=" + std::to_string(d));
    storeIntegrationPoints(out, d);
    out.close();
  }
}
