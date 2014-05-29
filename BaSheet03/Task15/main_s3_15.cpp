#include <vector>

#include <cmath>

namespace {
  const double S0 = 10.;
  const double r = 0.1;
  const double sigma = 0.25;
  const double T = 1.;
  const double K = 0.;
  const int M = 16;
  const double delta_t = M / T;
}

double geomBMIntegrand(std::vector<double> x) {
  double prod = S0;
  for (int i = 0; i < M; ++i) {
    const double ti = (i + 1) * delta_t;
    prod *= exp((r - 0.5 * sigma * sigma) * ti + sigma * sqrt(ti) * x[i]);
  }
  prod = pow(prod, 1. / M);
  return prod > K ? prod - K : 0.;
}

void main_s3_15() {

}
