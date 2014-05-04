/*
 * NormalCDF.cpp
 *
 *  Created on: 02.05.2014
 *      Author: BlueCrescent
 */

#include "NormalCDF.h"

#include <cmath>

#define A0 0.398942270991
#define A1 0.020133760596
#define A2 0.002946756074
#define B1 0.217134277847
#define B2 0.018576112465
#define B3 0.000643163695
#define C0 1.398247031184
#define C1 -0.360040248231
#define C2 0.022719786588
#define D0 1.460954518699
#define D1 -0.305459640162
#define D2 0.038611796258
#define D3 -0.003787400686

double NormalCDF(double x) {
  if (x < 0.)
    return 1. - NormalCDF(- x);
  if (x <= 1.87) {
    const double x2  = x * x;
    return 0.5 + x * (A0 + (A1 + A2 * x2) * x2) / (1. + (B1 + (B2 + B3 * x2) * x2) * x2);
  }
  else if (x < 6.) {
    return 1. - pow((C0 + (C1 + C2 * x) * x) / (D0 + (D1 + (D2 + D3 * x) * x) * x), 16.);
  }
  return 1.;
}

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

double NormalCDFInverse(double x) {
  const double p = x - 0.5;
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
