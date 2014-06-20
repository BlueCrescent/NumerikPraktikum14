#ifndef EC_BLACKSCHOLES_INCLUDED_
#define EC_BLACKSCHOLES_INCLUDED_

#include <cmath>

#include "NormalCDF.h"

inline double d1(double S0, double K, double r, double sigma, double T)
{
    return (log(S0 / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
}

inline double d2(double d1, double sigma, double T)
{
    return d1 - sigma * sqrt(T);
}

inline double Vcall(double S0, double K, double r, double sigma, double T)
{
    double d1_var = d1(S0, K, r, sigma, T);
    double d2_var = d2(d1_var, sigma, T);

    return S0 * NormalCDF(d1_var) - K * exp(-r * T) * NormalCDF(d2_var);
}

#endif
