#include <iostream>
#include <fstream>
#include "../Task2/NormalRejectionSampling.h"
#include "../Task2/Cpp11UniformDice.h"
#include "../mainIncludes.h"
using namespace std;

void writeDataToFile3(NormalRejectionSampling& SamplingDice){
  ofstream myfile;
  myfile.open ("data3");
  for(int i = 1; i < 1000000; i++) myfile << SamplingDice.roll()<<"\n";
  myfile.close();
}

int main3 () {
  Cpp11UniformDice UniformDice;
  NormalRejectionSampling SamplingDice(UniformDice);
  writeDataToFile3(SamplingDice);

  return 0;
}


