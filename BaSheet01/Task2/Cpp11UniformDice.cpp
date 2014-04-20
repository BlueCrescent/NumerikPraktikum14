#include "Cpp11UniformDice.h"
#include <ctime>

Cpp11UniformDice::Cpp11UniformDice() :
  Lower(0),
  Upper(1)
{
  this->generator.seed(time(NULL));
}

double Cpp11UniformDice::roll() {
  std::uniform_real_distribution<double> distribution(Lower, Upper);
  return distribution(generator);
}

void Cpp11UniformDice::setBounds(double _Lower, double _Upper) {
  Lower = _Lower;
  Upper = _Upper;
}
