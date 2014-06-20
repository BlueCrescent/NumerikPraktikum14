/*
 * NewtonRaphson.h
 *
 *  Created on: Jun 19, 2014
 *      Author: boris
 */

#ifndef NEWTONRAPHSON_H_
#define NEWTONRAPHSON_H_

#include <cmath>

#include "NormalCDF.h"

#define CALL true
#define PUT false

template<bool isCall>
inline double executeNewtonRaphsonAlgo(const double S0, const double r, const double T, const double K,
                                       const double historicalSigma, const double startSigma, const int maxIterations);

template<bool isCall>
inline double executeNewtonRaphsonAlgo(const double S0, const double r, const double T, const double K,
                                       const double historicalSigma, const double startSigma,
                                       const int maxIterations, const double historicalV);

template<bool isCall>
inline double computeDefaultSigma(const double S0, const double r, const double T, const double K,
                                  const double historicalSigma, const int maxIterations);




class NoConvergenceError {
public:
  NoConvergenceError(double lastSigma) :
    lastSigma(lastSigma)
  {}

  double getLastSigma() const {
    return lastSigma;
  }

private:
  const double lastSigma;
};


inline double computeD1(double S0, double r, double T, double K, double sigma) {
  return (log(S0 / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
}

inline double computeD2(double d1, double T, double sigma) {
  return d1 - sigma * sqrt(T);
}

inline double compEuropeanCallBS(double S0, double r, double T, double K, double d1, double d2) {
  return S0 * NormalCDF(d1) - K * exp(- r * T) * NormalCDF(d2);
}

inline double compEuropeanPutBS(double S0, double r, double T, double K, double d1, double d2) {
  return K * exp(- r * T) * NormalCDF(- d2) - S0 * NormalCDF(- d1);
}

template<bool isCall>
const double computeEuropeanBS(const double S0, const double r, const double T, const double K,
    const double historicalSigma) {
  const double d1 = computeD1(S0, r, T, K, historicalSigma);
  const double d2 = computeD2(d1, T, historicalSigma);
  return isCall ? compEuropeanCallBS(S0, r, T, K, d1, d2) : compEuropeanPutBS(S0, r, T, K, d1, d2);
}

inline double compRelPriceChangeByVolatility(double S0, double T, double d1) {
  return S0 * sqrt(0.5 * T / M_PI) * exp(- d1 * d1 / 2.);
}

template<bool isCall>
inline double makeNewtonRaphsonStep(double S0, double r, double T, double K, double prevSigma, double historicalV) {
  const double d1 = computeD1(S0, r, T, K, prevSigma);
  const double d2 = computeD2(d1, T, prevSigma);
  const double newV = isCall ? compEuropeanCallBS(S0, r, T, K, d1, d2) : compEuropeanPutBS(S0, r, T, K, d1, d2);

  const double relPriceChange = compRelPriceChangeByVolatility(S0, T, d1);

  return prevSigma - (newV - historicalV) / relPriceChange;
}

template<bool isCall>
inline double executeNewtonRaphsonAlgo(const double S0, const double r, const double T, const double K,
                                       const double historicalSigma, const double startSigma,
                                       const int maxIterations, const double historicalV) {
  double currentSigma = startSigma;
  for (int i = 1; i <= maxIterations; ++i) {
    const double newSigma = makeNewtonRaphsonStep<isCall>(S0, r, T, K, currentSigma, historicalV);
    if (fabs(currentSigma - newSigma) < 1e-10)
      return newSigma;
    currentSigma = newSigma;
  }
  throw NoConvergenceError(currentSigma);
}

template<bool isCall>
inline double executeNewtonRaphsonAlgo(const double S0, const double r, const double T, const double K,
                                       const double historicalSigma, const double startSigma, const int maxIterations) {
  const double historicalV = computeEuropeanBS<isCall>(S0, r, T, K, historicalSigma);

  return executeNewtonRaphsonAlgo<isCall>(S0, r, T, K,historicalSigma, startSigma, maxIterations, historicalV);
}

template<bool isCall>
inline double computeDefaultSigma(const double S0, const double r, const double T, const double K,
                                  const double historicalSigma, const int maxIterations) {
  const double historicalV = computeEuropeanBS<isCall>(S0, r, T, K, historicalSigma);

  return 2. * historicalV / (sqrt(T) * S0);
}

#endif /* NEWTONRAPHSON_H_ */
