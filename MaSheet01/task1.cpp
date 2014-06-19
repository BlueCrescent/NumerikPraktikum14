#include <fstream>
#include <vector>

#include "BinomialTreeMethod.h"

void task1() {
    const double r = 0.02;
    const double T = 2;
    const double sigma = 0.2;
    const double K = 10;
    const double S0 = 10;

    std::ofstream f;

    // Compute prices with different M.
    f.open("data_task1_1");
    for (int M = 1; M <= 128; M *= 2) {
        const double V = binomial_tree_method(S0, true, true, K, M, sigma, r, T / M);

        f << "{" << M << ", " << V << "}," << std::endl;
    }
    f.close();

    // Print values of discretization mesh for M = 32.
    f.open("data_task1_2");
    const int M = 32;
    const double dt = T / M;
    const std::vector<double> S = generate_discretization_mesh(S0, M, r, sigma, dt);
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= i; ++j)
            f << "{" << dt * i << ", " << S[idx(j, i)] << "}," << std::endl;
    }
    f.close();
}