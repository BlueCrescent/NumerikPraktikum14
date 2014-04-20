/*
 * NormalRejectionSampling.h
 *
 *  Created on: 10.04.2014
 *      Author: boris
 */

#ifndef NORMALREJECTIONSAMPLING_H_
#define NORMALREJECTIONSAMPLING_H_

#include "INormalDist.h"
#include "IUniformDist.h"

class NormalRejectionSampling: public INormalDistribution {
public:
  static const double MaxNormalDensity;
  static const double lower;
  static const double upper;

  NormalRejectionSampling(IUniformDist & UniformDice);

  ~NormalRejectionSampling() = default;

  double roll();

  static double NormalDensity(double x);

private:
  IUniformDist & UnifDice;
};

#endif /* NORMALREJECTIONSAMPLING_H_ */
