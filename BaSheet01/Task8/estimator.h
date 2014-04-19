/*
 * estimator.h
 *
 *  Created on: 18.04.2014
 *      Author: BlueCrescent
 */

#ifndef ESTIMATOR_H_
#define ESTIMATOR_H_

#include <ostream>

double naive_variance_estimator(const double * values, unsigned int size);

double variance_estimator(const double * values, unsigned int size);

double stream_variance_estimator_error(const double * values, unsigned int size, double sigma, std::ostream & out);

#endif /* ESTIMATOR_H_ */
