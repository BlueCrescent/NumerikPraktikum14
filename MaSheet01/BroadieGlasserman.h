#ifndef BROADIEGLASSERMAN_INCLUDED_
#define BROADIEGLASSERMAN_INCLUDED_

#include <ostream>

double Broadie_Glasserman_algorithm(double S0, bool isCall, double K, int N, int B,
                                    int M, double sigma, double r, double dt);

void stream_Broadie_Glaserman_tree(std::ostream & out, double S0, double K,
                                   int B, int M, double sigma, double r, double dt);
#endif