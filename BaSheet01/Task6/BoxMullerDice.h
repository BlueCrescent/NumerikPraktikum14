/*
 * BoxMullerDice.h
 *
 *  Created on: 18.04.2014
 *      Author: boris
 */

#ifndef BOXMULLERDICE_H_
#define BOXMULLERDICE_H_

#include "INormalDist.h"
#include "IUniformDist.h"
#include <utility>

class BoxMullerDice : public INormalDistribution {
public:
  ~BoxMullerDice();
  BoxMullerDice(IUniformDist& UnifDice);

  double roll();
  std::pair<double,double> rollPair();

  private:
    IUniformDist& UnifDice;
};

#endif /* BOXMULLERDICE_H_ */
