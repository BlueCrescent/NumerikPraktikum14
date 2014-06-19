#ifndef BINOMIALTREEMETHOD_INCLUDED_
#define BINOMIALTREEMETHOD_INCLUDED_

#include <vector>

double binomial_tree_method(double S0, bool isCall, bool isEuropean, double K,
                            int M, double sigma, double r, double dt);

std::vector<double> generate_discretization_mesh(double S0, int M, double r, double sigma, double dt);

inline int idx(int j, int i) {
    return (i * (i + 1)) / 2 + j;
}

#endif
