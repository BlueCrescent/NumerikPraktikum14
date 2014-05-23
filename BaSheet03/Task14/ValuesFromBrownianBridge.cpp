/*
 * ValuesFromBrownianBridge.cpp
 *
 *  Created on: 23.05.2014
 *      Author: boris
 */

#include "ValuesFromBrownianBridge.h"
#include <cmath>

ValuesFromBrownianBridge::ValuesFromBrownianBridge(double _sigma, double _r, double _T, double _S0, INormalDistribution& _Dice) :
level(0),
Dice(_Dice),
sigma(_sigma),
r(_r),
T(_T),
S0(_S0)
{
  t.push_back(0);
  t.push_back(T);
  W.push_back(0);
  W.push_back(sqrt(T)*Dice.roll());
  S.push_back(S0);
  S.push_back(evalS(T,W.back()));
}

void ValuesFromBrownianBridge::refineDiscritization() {
  const double delta_t = T / pow(2, level + 1);
  const int amountNewVals = pow(2, level);
  std::vector<double> tTmp;
  std::vector<double> WTmp;
  std::vector<double> STmp;
  tTmp.reserve(t.size() + amountNewVals);
  WTmp.reserve(W.size() + amountNewVals);
  STmp.reserve(S.size() + amountNewVals);
  for(int k = 0; k < amountNewVals; ++k) {
    tTmp.push_back(t[k]);
    tTmp.push_back(t[k] + delta_t);
    WTmp.push_back(W[k]);
    WTmp.push_back(0.5 * (W[k] + W[k + 1]) * sqrt(delta_t/2) * Dice.roll());
    STmp.push_back(S[k]);
    STmp.push_back(evalS(tTmp.back(), WTmp.back()));
  }
  tTmp.push_back(t.back());
  WTmp.push_back(W.back());
  STmp.push_back(S.back());
  t.swap(tTmp);
  W.swap(WTmp);
  S.swap(STmp);
  level++;
}

const std::vector<double>& ValuesFromBrownianBridge::getPathOfValues() const {
  return S;
}

double ValuesFromBrownianBridge::evalS(double t_j, double W_j) const {
  return S0*exp((r - 0.5 * sigma * sigma) * t_j + sigma * W_j);
}
