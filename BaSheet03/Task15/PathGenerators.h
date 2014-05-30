/*
 * PathGenerators.h
 *
 *  Created on: 30.05.2014
 *      Author: BlueCrescent
 */

#ifndef PATHGENERATORS_H_
#define PATHGENERATORS_H_

#include <vector>

std::vector<double> genRandomWalkPath(const std::vector<double> & uniformValues, double T);

std::vector<double> genBrownianBridgePath(const std::vector<double> & uniformValues, double T);

std::vector<double> genGeomBMPath(const std::vector<double> & wienerValues, double S0, double r, double sigma, double T, int M);



#endif /* PATHGENERATORS_H_ */
