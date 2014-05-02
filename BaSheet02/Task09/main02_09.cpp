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
#include "MonteCarloIntegrator.h"

using namespace std;

double exampleFunction(double x){
  return 1 + exp(0.5 * x);
}

void writeDataToFileTrapezodial2(int level){
  TrapezoidalIntegrator Integrator0;
  ofstream myfile;
  cout<<"open data_example_Trapezodial... ";
  myfile.open ("data_example_Trapezodial");
  myfile<<std::setprecision(20);
  cout<<"write data..."<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << abs(Integrator0.integrate(i, &exampleFunction) -2.29744) / 2.29744 << "\n";
  }
  myfile.close();
}
void writeDataToFileClenshaw2(int level){
  ClenshawIntegrator Integrator1;
  ofstream myfile;
  cout<<"open data_example_Clenshaw... ";
  myfile.open ("data_example_Clenshaw");
  myfile<<std::setprecision(20);
  cout<<"write data... "<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << abs(Integrator1.integrate(i, &exampleFunction) -2.29744) / 2.29744<< "\n";
  }
  myfile.close();
}
void writeDataToFileGaussLegendre2(int level){
  GaussLegendreIntegrator Integrator2;
  ofstream myfile;
  cout<<"open data_example_GaussLegendre... ";
  myfile.open ("data_example_GaussLegendre");
  myfile<<std::setprecision(20);
  cout<<"write data... "<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << abs(Integrator2.integrate(i, &exampleFunction)-2.29744) / 2.29744 << "\n";
  }
  myfile.close();
}
void writeDataToFileMonteCarlo2(int level){
  MonteCarloIntegrator Integrator3;
  ofstream myfile;
  cout<<"open data_example_MonteCarlo... ";
  myfile.open ("data_example_MonteCarlo");
  myfile<<std::setprecision(20);
  cout<<"write data..."<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << abs(Integrator3.integrate(i, &exampleFunction) -2.29744) / 2.29744 << "\n";
  }
  myfile.close();
}

void main_s2_09(){
  int level = 12;
  writeDataToFileTrapezodial2(level);
  writeDataToFileClenshaw2(level);
  writeDataToFileGaussLegendre2(level);
  writeDataToFileMonteCarlo2(level);
}
