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

double callFunction(double x){
  double S0 = 10., mu = 0.1, sigma = 0.2, T = 2, step = 2., K = 10., solution;
  solution = exp((mu - 0.5*sigma*sigma)*T + sigma*sqrt(T)*x);
  solution = abs(solution - K);
  return solution;
}

void writeDataToFileTrapezodial(int level){
  TrapezoidalIntegrator Integrator0;
  ofstream myfile;
  cout<<"open data_callF_Trapezodial... ";
  myfile.open ("data_callF_Trapezodial");
  myfile<<std::setprecision(20);
  cout<<"write data..."<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << Integrator0.integrate(i, &callFunction) << "\n";
  }
  myfile.close();
}
void writeDataToFileClenshaw(int level){
  ClenshawIntegrator Integrator1;
  ofstream myfile;
  cout<<"open data_callF_Clenshaw... ";
  myfile.open ("data_callF_Clenshaw");
  myfile<<std::setprecision(20);
  cout<<"write data... "<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << Integrator1.integrate(i, &callFunction) << "\n";
  }
  myfile.close();
}
void writeDataToFileGaussLegendre(int level){
  GaussLegendreIntegrator Integrator2;
  ofstream myfile;
  cout<<"open data_callF_GaussLegendre... ";
  myfile.open ("data_callF_GaussLegendre");
  myfile<<std::setprecision(20);
  cout<<"write data... "<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << Integrator2.integrate(i, &callFunction) << "\n";
  }
  myfile.close();
}
void writeDataToFileMonteCarlo(int level){
  MonteCarloIntegrator Integrator3;
  ofstream myfile;
  cout<<"open data_callF_MonteCarlo... ";
  myfile.open ("data_callF_MonteCarlo");
  myfile<<std::setprecision(20);
  cout<<"write data..."<<endl;
  for(int i = 1; i < level; ++i){
    myfile<< i << " " << Integrator3.integrate(i, &callFunction) << "\n";
  }
  myfile.close();
}

void main_s2_10(){
  int level = 12;
  writeDataToFileTrapezodial(level);
  writeDataToFileClenshaw(level);
  writeDataToFileGaussLegendre(level);
  writeDataToFileMonteCarlo(level);
}
