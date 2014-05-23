/*
 * ValuesFromBrownianBridge.h
 *
 *  Created on: 23.05.2014
 *      Author: boris
 */

#ifndef VALUESFROMBROWNIANBRIDGE_H_
#define VALUESFROMBROWNIANBRIDGE_H_

#include "INormalDist.h"
#include <vector>

class ValuesFromBrownianBridge {
public:
  ValuesFromBrownianBridge(double sigma, double r, double T, double S0, INormalDistribution& Dice);

  void refineDiscritization();

  const std::vector<double> & getPathOfValues() const;

private:
  int level;
  std::vector<double> t;
  std::vector<double> W;
  std::vector<double> S;
  INormalDistribution& Dice;
  double sigma, r, T, S0;

  double evalS(double t_j, double W_j) const;
};

#endif /* VALUESFROMBROWNIANBRIDGE_H_ */
