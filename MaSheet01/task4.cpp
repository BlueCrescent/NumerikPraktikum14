#include <fstream>

#include "BinomialTreeMethod.h"
#include "BroadieGlasserman.h"

void task4() {
    const double S0 = 10;
    const double r = 0.02;
    const double T = 2;
    const double sigma = 0.2;
    const double K = 10;
    const double B = 10;
    const int N = 100;

    // Generate American put and call option prices with
    // binomial tree method and Broadie-Glasserman algorithm.
    std::ofstream fAC_bin, fAP_bin, fAC_bga, fAP_bga;
    fAC_bin.open("data_task4AC_bin");
    fAP_bin.open("data_task4AP_bin");
    fAC_bga.open("data_task4AC_BGA");
    fAP_bga.open("data_task4AP_BGA");

    for (int M = 1; M <= 8; M *= 2) {
        // American call option prices with binomial tree method.
        const double Vcall_bin = binomial_tree_method(S0, true, false, K, M, sigma, r, T / M);
        fAC_bin << "{" << M << ", " << Vcall_bin << "}," << std::endl;
        // American put option prices with binomial tree method.
        const double Vput_bin = binomial_tree_method(S0, false, false, K, M, sigma, r, T / M);
        fAP_bin << "{" << M << ", " << Vput_bin << "}," << std::endl;
        // American call option prices with Broadie-Glasserman algorithm.
        const double Vcall_bga = Broadie_Glasserman_algorithm(S0, true, K, N, B, M, sigma, r, T / M);
        fAC_bga << "{" << M << ", " << Vcall_bga << "}," << std::endl;
        // American put option prices with Broadie-Glasserman algorithm.
        const double Vput_bga = Broadie_Glasserman_algorithm(S0, false, K, N, B, M, sigma, r, T / M);
        fAP_bga << "{" << M << ", " << Vput_bga << "}," << std::endl;
    }
    fAC_bin.close();
    fAP_bin.close();
    fAC_bga.close();
    fAP_bga.close();

    // Print data for Broadie-Glasserman mesh with M = 4.
    std::ofstream f_BGA_Plot;
    f_BGA_Plot.open("data_task4_BGA_Plot");

    stream_Broadie_Glaserman_tree(f_BGA_Plot, S0, K, B, 4, sigma, r, 0.5);

    f_BGA_Plot.close();
}
