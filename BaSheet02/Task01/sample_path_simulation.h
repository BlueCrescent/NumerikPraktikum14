/*
 * sample_path_simulation.h
 *
 *  Created on: 25.04.2014
 *      Author: BlueCrescent
 */

#ifndef SAMPLE_PATH_SIMULATION_H_
#define SAMPLE_PATH_SIMULATION_H_

#include "SimulateSDE.h"

#include "OnlineEstimator.h"

OnlineEstimator SDEsimulation_estimates(unsigned int num_sims, double time, double strike, SDEParameter params);

#endif /* SAMPLE_PATH_SIMULATION_H_ */
