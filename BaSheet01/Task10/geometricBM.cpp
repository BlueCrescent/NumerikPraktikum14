/*
 * SimulateSDE.cpp
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#include "geometricBM.h"

#include <cmath>

geometricBM::geometricBM(const double _start_value, const double _mu, const double _sigma, const double _step_width, INormalDistribution & _dice) :
  dice(_dice),
  start_value(_start_value),
  mu(_mu),
  sigma(_sigma),
  step_width(_step_width),
  current_time(0),
  current_wiener_value(0)
{
}

geometricBM::geometricBM(const geometricBMParameter params, INormalDistribution& _dice) :
  dice(_dice),
  start_value(params.start_value),
  mu(params.mu),
  sigma(params.sigma),
  step_width(params.step_width),
  current_time(0),
  current_wiener_value(0)
{
}

std::vector<double> geometricBM::compute_path_values(int M) {
  std::vector<double> values;
  for(int i = 0; i < M; i++){
    next_step();
    values.push_back(compute_current_value());
  }
  return values;
}

double geometricBM::compute_current_value() const {
  return start_value * exp((mu - 0.5 * sigma * sigma) * current_time + sigma * current_wiener_value);
}

double geometricBM::get_current_wiener_value() const {
  return current_wiener_value;
}

double geometricBM::get_current_time() const {
  return current_time;
}

void geometricBM::next_step() {
  wiener_process_step();
  current_time += step_width;
}

void geometricBM::wiener_process_step() {
  current_wiener_value += sqrt(step_width) * dice.roll();
}

