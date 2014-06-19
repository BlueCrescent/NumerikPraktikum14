#include <fstream>
#include <vector>

#include "BinomialTreeMethod.h"

void task3() {
	const double r = 0.02;
	const double T = 2;
	const double sigma = 0.2;
	const double K = 10;
	const int M = 64;
    
	std::ofstream f;

    // Print European put prices with different start values.
	f.open("data_task3E");
	for (int i = 0; i <= 10; i++) {
        const double S0 = 2 * i;
        const double V = binomial_tree_method(S0, false, true, K, M, sigma, r, T / M);
        
        f << "{" << S0 << ", " << V << "}, " << std::endl;
    }
    f.close();
    
    // Print American put prices with different start values.
    f.open("data_task3A");
	for (int i = 0; i <= 10; i++) {
        const double S0 = 2 * i;
        const double V = binomial_tree_method(S0, false, false, K, M, sigma, r, T / M);
        
        f << "{" << S0 << ", " << V << "}, " << std::endl;
    }
    f.close();
}