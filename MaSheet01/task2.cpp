#include <fstream>

#include <cmath>

#include "BinomialTreeMethod.h"
#include "EC_BlackScholes.h"

void task2() {
    const double r = 0.02;
    const double T = 2;
    const double sigma = 0.2;
    const double K = 10;
    const double S0 = 10;

    double Vcall_Result = Vcall(S0, K, r, sigma, T);

    std::ofstream f;
    f.open("data_task2");

    for (int M = 1; M <= 128; M *= 2) {
        const double V = binomial_tree_method(S0, true, true, K, M, sigma, r, T / M);

        f << "{" << M * M << ", " << fabs(Vcall_Result - V) << "}," << std::endl;
    }
    f.close();
}
