/*
 * MCMultiIntegrator.h
 *
 *  Created on: 28.05.2014
 *      Author: timm
 */

#ifndef MCMULTIINTEGRATOR_H_
#define MCMULTIINTEGRATOR_H_

#include "MultiVariateIntegrator.h"
#include "IUniformDist.h"

#include <cmath>

class MCMultiIntegrator: public MultiVariateIntegrator {
public:
  MCMultiIntegrator(IUniformDist & dice);

  template<typename T>
  long double integrate_efficient(int level, int d, T function) const;

  NodesAndWeights getNodesAndWeights(int l, int d) const;

private:
  IUniformDist & dice;

  std::vector<double> generateRandomNode(const int d) const;
};

//#include <fstream>

template<typename T>
long double MCMultiIntegrator::integrate_efficient(int level, int d, T function) const{
	const int N_l = pow(2, level) - 1;
	const double factor = 1. / N_l;
	
	long double result = 0.;
	for(int i = 0; i < N_l; ++i){
		std::vector<double> node = generateRandomNode(d);
		result += function(node) * factor;
	}
	
	return result;
}


#if 0
template<typename T>
long double MCMultiIntegrator::integrate_efficient(int level, int d, T function) const{
  const int N_l = pow(2, level) - 1;

  const double factor = 1. / pow((double) N_l, (double) d);

//  std::ofstream f;
//  f.open("data_TEST" + std::to_string(level) + " " + std::to_string(d));

  long double result = 0.;
  for (int run = 0; run < d; ++run) {
    for(int i = 0; i < N_l; ++i){
      std::vector<double> node = generateRandomNode(d);
//      f << function(node);
//      for (double v: node)
//        f << v << " ";
//      f << std::endl;
      result += function(node) * factor;
    }
  }
//  f.close();
//  for (int run = 0; run < d; ++run) {
//    result /= N_l;
//  }
  return result;
}

#endif

#endif /* MCMULTIINTEGRATOR_H_ */
