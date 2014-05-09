/*
 * asian_fair_prices.h
 *
 *  Created on: 08.05.2014
 *      Author: boris
 */

#ifndef ASIAN_FAIR_PRICES_H_
#define ASIAN_FAIR_PRICES_H_

#include <vector>

double calc_discrete_geometric_fairP(double start_value, double r, double sigma, double strike, double strike_time, unsigned int M);

double calc_continious_geometric_fairP(double start_value, double r, double sigma, double strike, double strike_time);

double evaluate_discr_geometric_payoff(const std::vector<double>& PathValues, double strike);


#endif /* ASIAN_FAIR_PRICES_H_ */
