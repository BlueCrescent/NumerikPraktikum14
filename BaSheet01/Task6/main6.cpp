#include <iostream>
#include <fstream>
#include "BoxMullerDice.h"
#include "Cpp11UniformDice.h"
#include "../mainIncludes.h"
using namespace std;

void writeDataToFile6(BoxMullerDice& SamplingDice){
  ofstream myfile;
  myfile.open ("data6");
  for(int i = 1; i < 1000000; i++){
    std::pair<double,double> tmp = SamplingDice.rollPair();
    myfile << tmp.first << " " << tmp.second <<"\n";
  }
  myfile.close();
}

int main6 () {
  Cpp11UniformDice UniformDice;
  BoxMullerDice SamplingDice(UniformDice);
  writeDataToFile6(SamplingDice);

  return 0;
}


