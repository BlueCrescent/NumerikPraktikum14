/*
 * bisectionMethod.h
 *
 *  Created on: 22.06.2014
 *      Author: BlueCrescent
 */

#ifndef BISECTIONMETHOD_H_
#define BISECTIONMETHOD_H_

#include <cmath>

struct Bisection_InvalidSearchIntervalException {
};

struct Bisection_NoConvergenceError {
  Bisection_NoConvergenceError(double left, double right) :
    left(left),
    right(right)
  {}

  const double left, right;
};

inline bool equalsZero(const double val) {
  return -1.e-16 < val && val < 1.e-16;
}

template<typename Function>
double executeBisectionMethod(Function func, double left, double right, const int maxIterations) {
  double valLeft = func(left), valRight = func(right);

  if (equalsZero(valLeft))
    return valLeft;
  if (equalsZero(valRight))
    return valRight;

  if (std::signbit(valLeft) == std::signbit(valRight))
    throw Bisection_InvalidSearchIntervalException();

  for (int i = 1; i < maxIterations; ++i) {
    const double mid = (left + right) / 2.;
    const double valMid = func(mid);
    if (equalsZero(valMid))
      return mid;
    if (std::signbit(valLeft) == std::signbit(valMid)) {
      left = mid;
      valLeft = valMid;
    } else {
      right = mid;
      valRight = valMid;
    }
  }

  throw Bisection_NoConvergenceError(left, right);
}



#endif /* BISECTIONMETHOD_H_ */
