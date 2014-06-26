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

template <typename EfficientIntegrator>
double integrateEfficient(const EfficientIntegrator& tmp, const int level, const int d){
  return tmp.integrateEfficient(level, d, multiF);
}

void storeIntegrationPoints(std::ofstream& out, int d) {
  const TrapezoidalIntegrator TrapezRule;
  const ClenshawIntegrator ClenshawRule;
  const double exact = integrateF(d);
  Cpp11UniformDice Dice;
  SparseGridIntegrator NodeSizer(TrapezRule);
  for (int l = 1; l < 4; ++l) {
    out << pow(pow(2., l) - 1., d) << " ";
    out << fabs(integrateEfficient(MCMultiIntegrator(Dice), l * d, d)            - exact ) / exact << " ";
    out << fabs(integrateEfficient(QMCMultiIntegrator(), l * d, d)               - exact ) / exact << " ";
    out << fabs(integrateEfficient(ProductIntegrator(TrapezRule), l, d)      - exact ) / exact << " ";
    out << fabs(integrateEfficient(ProductIntegrator(ClenshawRule), l, d)    - exact ) / exact << " ";
    out << NodeSizer.getNodesAndWeights(l*2,d).getSize() << " "
        << fabs(integrate(SparseGridIntegrator(TrapezRule), l*2, d)   - exact ) / exact << " ";
    out << fabs(integrate(SparseGridIntegrator(ClenshawRule), l*2, d) - exact ) / exact << " ";
    out << pow(2., l * d) - 1.;
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
