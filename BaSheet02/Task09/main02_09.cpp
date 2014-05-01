/*
 * main02_09.cpp
 *
 *  Created on: 01.05.2014
 *      Author: boris
 */

#include <cmath>
#include <iostream>
#include <fstream>
#include "NumericalIntegrator.h"
#include "TrapezoidalIntegrator.h"
#include "ClenshawIntegrator.h"
#include "GaussLegendreIntegrator.h"

using namespace std;

double exampleFunction(double x){
  return 1 + exp(0.5 * x);
}

void writeDataToFileTrapezodial(){
  TrapezoidalIntegrator Integrator0;
  ofstream myfile;
  cout<<"open dataTrapezodial... ";
  myfile.open ("dataTrapezodial");
  cout<<"write data..."<<endl;
  for(int i = 0; i < 10; ++i){
    myfile<< i << " " << Integrator0.integrate(4, &exampleFunction) << "/n";
  }
  myfile.close();
}
void writeDataToFileClenshaw(){
  ClenshawIntegrator Integrator1;
  ofstream myfile;
  cout<<"open dataClenshaw... ";
  myfile.open ("dataClenshaw");
  cout<<"write data... "<<endl;
  for(int i = 0; i < 10; ++i){
    myfile<< i << " " << Integrator1.integrate(4, &exampleFunction) << "/n";
  }
  myfile.close();
}
void writeDataToFileGaussLegendre(){
  GaussLegendreIntegrator Integrator2;
  ofstream myfile;
  cout<<"open dataGaussLegendre... ";
  myfile.open ("dataGaussLegendre");
  cout<<"write data... "<<endl;
  for(int i = 0; i < 10; ++i){
    myfile<< i << " " << Integrator2.integrate(4, &exampleFunction) << "/n";
  }
  myfile.close();
}

void main_s2_09(){
  writeDataToFileTrapezodial();
  writeDataToFileClenshaw();
  writeDataToFileGaussLegendre();
}
