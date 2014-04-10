#ifndef RANDOMDICE_H
#define RANDOMDICE_H

#include <random>
#include <time.h>
#include "IUniformDist.h"

class Cpp11UniformDice : public IUniformDist
{
public:
    // Methods
    Cpp11UniformDice();
    double rollExpDist(double Lambda);
    double rollDiscrUnifDist(int);
    double rollContUnifDist(double);

    // TESTING
    double computeAverage(int Loops);
    double rollExpDist();

private:
    std::default_random_engine generator;
};

#endif // RANDOMDICE_H
