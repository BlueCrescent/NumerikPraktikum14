/*
 * CDFNormalDice.h
 *
 *  Created on: 18.04.2014
 *      Author: timm
 */

#ifndef CDFNORMALDICE_H_
#define CDFNORMALDICE_H_

#include "INormalDist.h"
#include "IUniformDist.h"

class CDFNormalDice: public INormalDistribution {
public:
  CDFNormalDice(IUniformDist & UniformDice);

  ~CDFNormalDice();

  double roll();

  static double NormalCDFInverse(double x);

private:
  IUniformDist & UniformDice;
};

#endif /* CDFNORMALDICE_H_ */
