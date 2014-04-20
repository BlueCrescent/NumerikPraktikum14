/*
 * convergence_plot_data.h
 *
 *  Created on: 20.04.2014
 *      Author: BlueCrescent
 */

#ifndef CONVERGENCE_PLOT_DATA_H_
#define CONVERGENCE_PLOT_DATA_H_

#include <fstream>

#include "INormalDist.h"

void generate_convergence_data_with(double mu, double sigma, long long unsigned int size, INormalDistribution & dice);

#endif /* CONVERGENCE_PLOT_DATA_H_ */
