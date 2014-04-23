/*
 * OnlineEstimator.h
 *
 *  Created on: 23.04.2014
 *      Author: BlueCrescent
 */

#ifndef ONLINEESTIMATOR_H_
#define ONLINEESTIMATOR_H_

class OnlineEstimator {
public:
  OnlineEstimator();

  ~OnlineEstimator() = default;

  long long unsigned int get_sample_count() const;

  double get_current_mean() const;

  double get_current_variance() const;

  void add_sample(double value);

private:
  long long unsigned int sample_count;
  double mean;
  double variance_sum;

  void variance_estimation_step(const double value);
};

inline long long unsigned int OnlineEstimator::get_sample_count() const {
  return sample_count;
}

inline double OnlineEstimator::get_current_mean() const {
  return mean;
}

inline double OnlineEstimator::get_current_variance() const {
  if (sample_count <= 1)
    return 0.;
  return variance_sum / (sample_count - 1);
}

#endif /* ONLINEESTIMATOR_H_ */
