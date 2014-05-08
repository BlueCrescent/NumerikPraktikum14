/*
 * asian_fair_prices.h
 *
 *  Created on: 08.05.2014
 *      Author: boris
 */

#ifndef ASIAN_FAIR_PRICES_H_
#define ASIAN_FAIR_PRICES_H_

double discrete_geometric(double start_value, double mu, double sigma, double strike, double strike_time, unsigned int M, double r);

double continious_geometric(double start_value, double mu, double sigma, double strike, double strike_time, double r);



#endif /* ASIAN_FAIR_PRICES_H_ */
