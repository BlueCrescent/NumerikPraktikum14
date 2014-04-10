/*
 * IDice.h
 *
 *  Created on: 10.04.2014
 *      Author: boris
 */

#ifndef IDICE_H_
#define IDICE_H_

class INormalDistribution {
public:
  virtual ~INormalDistribution(){}
  virtual double roll() = 0;
};

#endif /* IDICE_H_ */

