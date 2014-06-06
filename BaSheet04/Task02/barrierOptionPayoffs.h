/*
 * barrierOptionPayoffs.h
 *
 *  Created on: Jun 6, 2014
 *      Author: boris
 */

#ifndef BARRIEROPTIONPAYOFFS_H_
#define BARRIEROPTIONPAYOFFS_H_

inline double evaluateDownOutCallPayoff(const std::vector<double> & pathValues, double strike, double barrier) {
  for (unsigned int i = 0; i < pathValues.size(); ++i) {
    if (pathValues[i] <= barrier)
      return 0.;
  }

  const double maturityValue = pathValues.back();
  return maturityValue > strike ? maturityValue - strike : 0.;
}


#endif /* BARRIEROPTIONPAYOFFS_H_ */
