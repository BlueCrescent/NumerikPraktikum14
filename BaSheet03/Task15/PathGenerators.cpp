/*
 * PathGenerators.cpp
 *
 *  Created on: 30.05.2014
 *      Author: BlueCrescent
 */

#include "PathGenerators.h"
#include "NormalCDF.h"

#include <cmath>
#include <cassert>

std::vector<double> genRandomWalkPath(const std::vector<double>& uniformValues, double T) {
  std::vector<double> path;
  path.reserve(uniformValues.size());
  const double sqrt_dt = sqrt(T / uniformValues.size());

  path.push_back(sqrt_dt * NormalCDFInverse(uniformValues[0]));
  for (unsigned int i = 1; i < uniformValues.size(); ++i) {
    path.push_back(path[i - 1] + sqrt_dt * NormalCDFInverse(uniformValues[i]));
  }

  return path;
}

inline void generateLevel(int step, double a_sqrt, const std::vector<double>& uniformValues,
                          std::vector<double>& path) {
  assert(path[step] == 0.);
  path[step] = 0.5 * path[step * 2] + a_sqrt * uniformValues[step];
  for (unsigned int i = 3 * step; i < uniformValues.size() - 1; i += 2 * step) {
    assert(path[i] == 0.);
    path[i] = 0.5 * (path[i - step] + path[i + step]) + a_sqrt * NormalCDFInverse(uniformValues[i]);
  }
}

void iterateLevels(double T, const std::vector<double>& uniformValues, std::vector<double>& path) {
  double a_sqrt = sqrt(T / 2.);
  int step = uniformValues.size();

  for (unsigned int levelSize = 2; levelSize <= uniformValues.size(); levelSize *= 2) {
    assert(step % 2 == 0);
    step /= 2;
    a_sqrt /= sqrt(2.);

    generateLevel(step, a_sqrt, uniformValues, path);
  }
}

std::vector<double> genBrownianBridgePath(const std::vector<double>& uniformValues, double T) {
  std::vector<double> path(uniformValues.size());
  path.back() = sqrt(T) * NormalCDFInverse(uniformValues.back());

  iterateLevels(T, uniformValues, path);

  return path;
}

double evalS(double t_j, double W_j, double S0, double r, double sigma) {
  return S0*exp((r - 0.5 * sigma * sigma) * t_j + sigma * W_j);
}

std::vector<double> genGeomBMPath(const std::vector<double>& wienerValues,
                                  double S0, double r, double sigma, double T, int M) {
  std::vector<double> S;
  S.reserve(wienerValues.size());
  const double delta_t = T / M;
  double t_i = 0;

  for (unsigned int i = 0; i < wienerValues.size(); ++i) {
    t_i += delta_t;
    S.push_back(evalS(t_i, wienerValues[i], S0, r, sigma));
  }

  return S;
}
