/*
 * task1.cpp
 *
 *  Created on: 10.04.2014
 *      Author: timm
 */

#include <cstdlib>
#include <cstdio>
#include <gsl/gsl_rng.h>

int main1() {
  printf("%lf\n", (double)rand() / RAND_MAX);   // *

  gsl_rng* r;
  r = gsl_rng_alloc(gsl_rng_mt19937);
  printf("%lf\n", gsl_rng_uniform(r));
  gsl_rng_free(r);

  return 0;
}




