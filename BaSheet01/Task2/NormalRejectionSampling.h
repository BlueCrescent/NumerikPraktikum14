/*
 * NormalRejectionSampling.h
 *
 *  Created on: 10.04.2014
 *      Author: boris
 */

#ifndef NORMALREJECTIONSAMPLING_H_
#define NORMALREJECTIONSAMPLING_H_

#include "INormalDist.h"

class NormalRejectionSampling: public INormalDistribution {
public:
  NormalRejectionSampling();
  ~NormalRejectionSampling();
};

#endif /* NORMALREJECTIONSAMPLING_H_ */
