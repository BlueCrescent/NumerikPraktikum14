#include <vector>
#include <cmath>

#include "BinomialTreeMethod.h"

double Beta(double r, double sigma, double dt)
{
    return 0.5 * (exp(- r * dt) + exp((r + sigma * sigma) * dt));
}

double U(double beta)
{
    return beta + sqrt(beta * beta - 1);
}

double D(double beta)
{
    return beta - sqrt(beta * beta - 1);
}

double P(double r, double dt, double u, double d)
{
    return (exp(r * dt) - d) / (u - d);
}

std::vector<double> forward_phase(double S0, double u, double d, int M)
{
    std::vector<double> S;
    S.reserve((M + 1) * (M + 2) / 2);
    S.push_back(S0);

    for (int i = 1; i <= M; i++)
        for (int j = 0; j <= i; j++)
            S.push_back(S0 * pow(u, j) * pow(d, i - j));

    return S;
}

std::vector<double> generate_discretization_mesh(double S0, int M, double r,
                                                 double sigma, double dt)
{
    const double beta = Beta(r, sigma, dt);
    const double u = U(beta);
    const double d = D(beta);
    return forward_phase(S0, u, d, M);
}

std::vector<double> generate_last_values(int M, double K, bool isCall,
                                         const std::vector<double> & S)
{
    std::vector<double> V((M + 1) * (M + 2) / 2);
    const double factor = isCall ? 1. : -1.;

    for (int j = 0; j <= M; j++)
    {
        const double value = factor * (S[idx(j, M)] - K);
        V[idx(j, M)] = value > 0. ? value : 0.;
    }

    return V;
}

void backwards_phase_european(int M, double r, double dt, double p, std::vector<double> & V)
{
    for (int i = M - 1; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            V[idx(j, i)] = exp(- r * dt) * (p * V[idx(j + 1, i + 1)] + (1 - p) * V[idx(j, i + 1)]);
}

void backwards_phase_american(int M, double K, double r, double dt, double p, bool isCall,
                              const std::vector<double> & S, std::vector<double> & V)
{
    const double factor = isCall ? 1. : -1.;
    for (int i = M - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            const double value1 = factor * (S[idx(j, i)] - K);
            const double value2 = exp(-r * dt) * (p * V[idx(j + 1, i + 1)] + (1 - p) * V[idx(j, i + 1)]);
            V[idx(j, i)] = fmax(value1 ? value1 : 0, value2);
        }
    }
}

double binomial_tree_method(double S0, bool isCall, bool isEuropean, double K,
                            int M, double sigma, double r, double dt)
{
    const double beta = Beta(r, sigma, dt);
    const double u = U(beta);
    const double d = D(beta);
    const double p = P(r, dt, u, d);

    // Step 1
    std::vector<double> S = forward_phase(S0, u, d, M);

    // Step 2
    std::vector<double> V = generate_last_values(M, K, isCall, S);

    // Step 3
    if (isEuropean)
        backwards_phase_european(M, r, dt, p, V);
    else
        backwards_phase_american(M, K, r, dt, p, isCall, S, V);

    return V[0];
}
