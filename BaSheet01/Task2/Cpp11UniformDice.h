#ifndef RANDOMDICE_H
#define RANDOMDICE_H

#include <random>
#include "IUniformDist.h"

class Cpp11UniformDice : public IUniformDist
{
public:
    // Methods
    Cpp11UniformDice();

    double roll();

    void setBounds(double Lower, double Upper);
//
//    double rollExpDist(double Lambda);
//    double rollDiscrUnifDist(int);
//    double rollContUnifDist(double);
//
//    // TESTING
//    double computeAverage(int Loops);
//    double rollExpDist();

private:
    double Lower, Upper;
    std::default_random_engine generator;
};

#endif // RANDOMDICE_H
