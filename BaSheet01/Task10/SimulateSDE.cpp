/*
 * SimulateSDE.cpp
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#include "SimulateSDE.h"

#include <cmath>

SDE::SDE(const double _start_value, const double _mu, const double _sigma, const double _step_width, INormalDistribution & _dice) :
  dice(_dice),
  start_value(_start_value),
  mu(_mu),
  sigma(_sigma),
  step_width(_step_width),
  current_time(0),
  current_wiener_value(0)
{
}

double SDE::compute_current_value() const {
  return start_value * exp((mu + 0.5 * sigma * sigma) * current_time + sigma * current_wiener_value);
}

double SDE::get_current_wiener_value() const {
  return current_wiener_value;
}

double SDE::get_current_time() const {
  return current_time;
}

void SDE::next_step() {
  wiener_process_step();
  current_time += step_width;
}

void SDE::wiener_process_step() {
  current_wiener_value += sqrt(step_width) * dice.roll();
}

