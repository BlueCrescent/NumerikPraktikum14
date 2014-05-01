/*
 * main02_09.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "NumericalIntegrator.h"
#include "TrapezoidalIntegrator.h"
#include "ClenshawIntegrator.h"
#include "GaussLegendreIntegrator.h"

using namespace std;

double exampleFunction(double x){
  return 1 + exp(0.5 * x);
}

void writeDataToFileTrapezodial(int level){
  TrapezoidalIntegrator Integrator0;
  ofstream myfile;
  cout<<"open data_integrate_Trapezodial... ";
  myfile.open ("data_integrate_Trapezodial");
  myfile<<std::setprecision(20);
  cout<<"write data..."<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << Integrator0.integrate(i, &exampleFunction) << "\n";
  }
  myfile.close();
}
void writeDataToFileClenshaw(int level){
  ClenshawIntegrator Integrator1;
  ofstream myfile;
  cout<<"open data_integrate_Clenshaw... ";
  myfile.open ("data_integrate_Clenshaw");
  myfile<<std::setprecision(20);
  cout<<"write data... "<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << Integrator1.integrate(i, &exampleFunction) << "\n";
  }
  myfile.close();
}
void writeDataToFileGaussLegendre(int level){
  GaussLegendreIntegrator Integrator2;
  ofstream myfile;
  cout<<"open data_integrate_GaussLegendre... ";
  myfile.open ("data_integrate_GaussLegendre");
  myfile<<std::setprecision(20);
  cout<<"write data... "<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << Integrator2.integrate(i, &exampleFunction) << "\n";
  }
  myfile.close();
}

void main_s2_09(){
  int level = 12;
  writeDataToFileTrapezodial(level);
  writeDataToFileClenshaw(level);
  writeDataToFileGaussLegendre(level);
}
