#include <vector>

#include <cmath>
#include <cstdlib>
#include <ctime>

#include "BroadieGlasserman.h"
#include "NormalCDF.h"

double Tj_high_ij(double prevS, bool isCall, double K, double r,
                  double dt, int B, std::vector<double> Tjj_high_k)
{
    double diff = (prevS - K) * (isCall ? 1. : -1.);
    double Sum_Tjj_high = 0;

    for (int i = 1; i <= B; i++)
        Sum_Tjj_high += Tjj_high_k[i - 1];

    return fmax(diff > 0. ? diff : 0., exp(- r * dt) * (1. / B) * Sum_Tjj_high);
}

double eta(double prevS, bool isCall, double K, int k, double r,
           double dt, int B, std::vector<double> Tjj_low_k)
{
    double Sum_Tjj_low = 0;

    for (int i=1; i<=B; i++) {
        if (i != k)
            Sum_Tjj_low += Tjj_low_k[i-1];
    }

    double diff = (prevS - K) * (isCall ? 1. : -1.);
    double fun1 = diff > 0. ? diff : 0.;
    double fun2 = 1. / (B - 1.) * exp(- r * dt) * Sum_Tjj_low;

    if (fun1 >= fun2)
        return fun1;
    else
        return exp(- r * dt) * Tjj_low_k[k - 1];
}

double Tj_low_ij(double prevS, bool isCall, double K, double r,
                 double dt, int B, std::vector<double> Tjj_low_k)
{
    double Sum_Tjj_low = 0;

    for (int i = 1; i <= B; i++) {
        Sum_Tjj_low += eta(prevS, isCall, K, i, r, dt, B, Tjj_low_k);
    }

    return Sum_Tjj_low / (double) B;
}

void compute_estimated_value(double prevS, bool isCall, double K, int B, int M, double sigma,
                             double r, double dt, int j, double & Tj_high, double & Tj_low)
{
    std::vector<double> Tjj_high_k(B);
    std::vector<double> Tjj_low_k(B);

    for (int k = 1; k <= B; k++) {
        double normalValue = NormalCDFInverse(rand() / (double) RAND_MAX);
        double nextS = prevS * exp(sigma * sqrt(dt) * normalValue + (r - 0.5 * sigma * sigma) * dt);

        if (j + 1 == M) {
            double diff = (nextS - K) * (isCall ? 1. : -1.);
            Tjj_high_k[k - 1] = diff > 0. ? diff : 0.;
            Tjj_low_k[k - 1] = Tjj_high_k[k - 1];
        } else
            compute_estimated_value(nextS, isCall, K, B, M, sigma, r, dt,
                                    j + 1, Tjj_high_k[k - 1], Tjj_low_k[k - 1]);
    } // end for

    Tj_high = Tj_high_ij(prevS, isCall, K, r, dt, B, Tjj_high_k);
    Tj_low = Tj_low_ij(prevS, isCall, K, r, dt, B, Tjj_low_k);
}

double Broadie_Glasserman_algorithm(double S0, bool isCall, double K, int N, int B,
                                    int M, double sigma, double r, double dt)
{
    srand(time(NULL));
    int j = 0;
    double V = 0;

    for (int i = 1; i <= N; i++) {
        double Tj_high;
        double Tj_low;

        compute_estimated_value(S0, isCall, K, B, M, sigma, r, dt, j, Tj_high, Tj_low);

        V = V + 0.5 * (Tj_high + Tj_low);
    }
    return V / N;
}


void generate_next_S(std::ostream & out, double prevS, double K, int B,
                     int M, double sigma, double r, double dt, int j)
{
    const double t_jj = dt * (j + 1);
    for (int k = 1; k <= B; k++) {
        const double normalValue = NormalCDFInverse(rand() / (double) RAND_MAX);
        const double nextS = prevS * exp(sigma * sqrt(dt) * normalValue + (r - 0.5 * sigma * sigma) * dt);

        out << "{" << t_jj << ", " << nextS << "}," << std::endl;

        if (j + 1 != M)
            generate_next_S(out, nextS, K, B, M, sigma, r, dt, j + 1);
    }
}

void stream_Broadie_Glaserman_tree(std::ostream & out, double S0, double K,
                                   int B, int M, double sigma, double r, double dt)
{
    srand(time(NULL));
    out << "{" << 0 << ", " << S0 << "}," << std::endl;
    generate_next_S(out, S0, K, B, M, sigma, r, dt, 0);
}
