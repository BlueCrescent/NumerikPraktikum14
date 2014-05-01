/*
 * main02_09.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include <cmath>
#include "NumericalIntegrator.h"
#include "TrapezoidalIntegrator.h"
#include "ClenshawIntegrator.h"
#include "GaussLegendreIntegrator.h"

double exampleFunction(double x){
  return 1 + exp(0.5 * x);
}

void main02_09(){
  double Solution;
  TrapezoidalIntegrator Integrator0;
  Solution = Integrator0.integrate(20, &exampleFunction);
  ClenshawIntegrator Integrator1;
  Solution = Integrator1.integrate(20, &exampleFunction);
  GaussLegendreIntegrator Integrator2;
  //Solution = Integrator2.integrate(20, &exampleFunction);
}
