#include "Cpp11UniformDice.h"
#include "time.h"

Cpp11UniformDice::Cpp11UniformDice(){
    this->generator.seed(time_t(NULL));
}
double Cpp11UniformDice::computeAverage(int Loops){
    double Average = 0;
    for(int i = 0; i < Loops; i++) Average += this->rollExpDist()/(double)Loops;
    return Average;
}
double Cpp11UniformDice::rollExpDist(){
    std::exponential_distribution<double> distribution(1.);
    return distribution(generator);
}
double Cpp11UniformDice::rollExpDist(double Lambda){
    std::exponential_distribution<double> distribution(Lambda);
    return distribution(generator);
}

double Cpp11UniformDice::rollContUnifDist(double tmp){
    std::uniform_real_distribution<double> distribution(0,tmp);
    return distribution(generator);
}
double Cpp11UniformDice::rollDiscrUnifDist(int tmp)
{
    if(tmp > 0){
        std::uniform_int_distribution<int> distribution(1, tmp);
        return distribution(generator);
    }
    else return 0;
}
