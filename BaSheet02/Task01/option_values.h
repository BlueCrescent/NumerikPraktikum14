/*
 * option_values.h
 *
 *  Created on: 26.04.2014
 *      Author: BlueCrescent
 */

#ifndef OPTION_VALUES_H_
#define OPTION_VALUES_H_

inline double call_option_value(const double price, const double strike) {
  return price > strike ? price - strike : 0.;
}

inline double put_option_value(const double price, const double strike) {
  return strike > price ? strike - price : 0.;
}



#endif /* OPTION_VALUES_H_ */
