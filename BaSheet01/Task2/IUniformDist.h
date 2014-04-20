/*
 * IUniformDist.h
 *
 *  Created on: 10.04.2014
 *      Author: boris
 */

#ifndef IUNIFORMDIST_H_
#define IUNIFORMDIST_H_

class IUniformDist {
public:
  virtual ~IUniformDist() {}

  virtual double roll() = 0;

  virtual void setBounds(double Lower, double Upper) = 0;

  IUniformDist & operator= (const IUniformDist & other) = delete;
};

#endif /* IUNIFORMDIST_H_ */

