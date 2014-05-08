/*
 * geometricBM.h
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#ifndef SIMULATESDE_H_
#define SIMULATESDE_H_

#include "INormalDist.h"
#include <vector>

struct geometricBMParameter {
  double start_value;
  double mu;
  double sigma;
  double step_width;
};

class geometricBM {
public:
  geometricBM(double start_value, double mu, double sigma, double step_width, INormalDistribution & dice);

  geometricBM(geometricBMParameter params, INormalDistribution & dice);

  std::vector<double> compute_path_values(int M);

  double compute_current_value() const;

  double get_current_wiener_value() const;

  double get_current_time() const;

  void next_step();

private:
  INormalDistribution & dice;

  const double start_value;
  const double mu, sigma;
  const double step_width;
  double current_time;
  double current_wiener_value;

  void wiener_process_step();
};


#endif /* SIMULATESDE_H_ */
