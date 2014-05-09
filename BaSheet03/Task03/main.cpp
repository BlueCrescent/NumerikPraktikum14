/*
 * main.cpp
 *
 *  Created on: 08.05.2014
 *      Author: boris
 */

#include "geometricBM.h"
#include "Cpp11NormalDice.h"
#include "asian_fair_prices.h"
#include <fstream>

void main_s3_03() {
  const double start_value = 10, r = 0.1, sigma = 0.25, delta1 = 0.1, strike = 10, T = 1., delta2 = 0.005;
  const int M1 = 10, M2 = 200;
  geometricBMParameter Parameters{start_value,r,sigma,delta1};
  Cpp11NormalDice Dice;
  std::ofstream myfile;

  myfile.open("data_s3_03_M10");
  const double expectedPayoff1 = calc_discrete_geometric_fairP(start_value,r,sigma,strike,T,M1);
  double sum = 0;
  for(int i = 1; i < 100; i++){
    geometricBM Path(Parameters, Dice);
    const std::vector<double> values = Path.compute_path_values(M1);
    sum += evaluate_discr_geometric_payoff(values, strike);
    myfile << i << " " << (sum/i - expectedPayoff1)/expectedPayoff1;
  }
  myfile.close();

  myfile.open("data_s3_03_M200");
  Parameters.step_width = delta2;
  const double expectedPayoff2 = calc_discrete_geometric_fairP(start_value,r,sigma,strike,T,M2);
  sum = 0;
  for(int i = 1; i < 100; i++){
    geometricBM Path(Parameters, Dice);
    const std::vector<double> values = Path.compute_path_values(M2);
    sum += evaluate_discr_geometric_payoff(values, strike);
    myfile << i << " " << (sum/i - expectedPayoff2)/expectedPayoff2;
  }
  myfile.close();

}
