/*
 * CDFNormalDice.cpp
 *
 *  Created on: 18.04.2014
 *      Author: timm
 */

#define E0 2.50662823884
#define E1 -18.61500062529
#define E2 41.39119773534
#define E3 -25.44106049637
#define F0 -8.47351093090
#define F1 23.08336743743
#define F2 -21.06224101826
#define F3 3.13082909833
#define G0 0.3374754822726147
#define G1 0.9761690190917186
#define G2 0.1607979714918209
#define G3 0.0276438810333863
#define G4 0.0038405729373609
#define G5 0.0003951896511919
#define G6 0.0000321767881768
#define G7 0.0000002888167364
#define G8 0.0000003960315187

#include "CDFNormalDice.h"

#include <cmath>

CDFNormalDice::CDFNormalDice(IUniformDist & _UniformDice) :
  UniformDice(_UniformDice)
{
  UniformDice.setBounds(0., 1.);
}

double CDFNormalDice::roll() {
  return NormalCDFInverse(UniformDice.roll());
}

inline double CDFNormalDice::NormalCDFInverse(double x) {
  double p = x - 0.5;
  double r;
  if (fabs(p) < 0.42) {
    r = pow(p, 2.);
    return p * (((E3 * r + E2) * r + E1) * r + E0) / ((((F3 * r + F2) * r + F1) * r + F0) * r + 1.0);
  } else {
    if (p < 0)
      r = x;
    else
      r = 1 - x;

    r = log(-log(r));
    r = G0 + r * (G1 + r * (G2 + r * (G3 + r * (G4 + r * (G5 + r * (G6 + r * (G7 + r * G8)))))));

    if (p < 0)
      return -r;
    else
      return r;
  }
}
