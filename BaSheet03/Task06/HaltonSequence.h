/*
 * HaltonSequence.h
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#ifndef HALTONSEQUENCE_H_
#define HALTONSEQUENCE_H_

#include <vector>

namespace Halton {
  extern double eps;
}

std::vector<double> generateFirstPoint(int dim);

std::vector<double> generateNextHaltonValue(const std::vector<double> & prevValue);

std::vector<std::vector<double> > generateHaltonSequence(int dim, int number);

#endif /* HALTONSEQUENCE_H_ */
