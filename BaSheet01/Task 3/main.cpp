#include <iostream>
#include <fstream>
#include "../Task2/NormalRejectionSampling.h"
#include "../Task2/Cpp11UniformDice.h"
using namespace std;

void writeDataToFile(NormalRejectionSampling& SamplingDice){
  ofstream myfile;
  myfile.open ("data");
  for(int i = 1; i < 1000000; i++) myfile << SamplingDice.roll()<<"\n";
  myfile.close();
}

int main () {
  Cpp11UniformDice UniformDice;
  NormalRejectionSampling SamplingDice(UniformDice);
  writeDataToFile(SamplingDice);

  return 0;
}


