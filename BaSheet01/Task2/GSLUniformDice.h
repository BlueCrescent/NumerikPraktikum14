/*
 * GSLUniformDice.h
 *
 *  Created on: 17.04.2014
 *      Author: timm
 */

#ifndef GSLUNIFORMDICE_H_
#define GSLUNIFORMDICE_H_

#include "IUniformDist.h"

#include <gsl/gsl_rng.h>

class GSLUniformDice: public IUniformDist {
public:
  GSLUniformDice();

  ~GSLUniformDice();

  double roll();

  void setBounds(double Lower, double Upper);

  GSLUniformDice(const GSLUniformDice & other) = delete;
  GSLUniformDice & operator= (const GSLUniformDice & other) = delete;
private:
  double Lower, Upper;
  gsl_rng* RandomGenerator;
};

#endif /* GSLUNIFORMDICE_H_ */
