/*
 * geometricBMdensity.h
 *
 *  Created on: 09.05.2014
 *      Author: boris
 */

#ifndef GEOMETRICBMDENSITY_H_
#define GEOMETRICBMDENSITY_H_

#include <vector>

class geometricBMdensity {
public:
  geometricBMdensity(const double mu, const double sigma, const double start_value);

  std::vector<double> operator() (double T, int M, double s);

private:
  const double mu;
  const double sigma;
  const double start_value;
};

#endif /* GEOMETRICBMDENSITY_H_ */
