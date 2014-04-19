/*
 * estimator.h
 *
 *  Created on: 18.04.2014
 *      Author: BlueCrescent
 */

#include <ostream>

double naive_variance_estimator(const double * values, unsigned int size);

double variance_estimator(const double * values, unsigned int size);

double variance_estimator_stream_error(const double * values, unsigned int size, double sigma, std::ostream & out);


