/*
 * main_s3_07.cpp
 *
 *  Created on: 15.05.2014
 *      Author: boris
 */

#include "HaltonSequence.h"
#include "Cpp11UniformDice.h"

#include <vector>
#include <fstream>

void printHaltonSequence(const int dim, const int number, std::ostream& output) {
  const std::vector<std::vector<double> > nodes = generateHaltonSequence(dim, number);

  for (unsigned int i = 0; i < nodes.size(); ++i) {
    for (int j = 0; j < dim; ++j)
      output << nodes[i][j] << " ";
    output << std::endl;
  }
}

void printUniformPoints(const int dim, const int number, std::ostream& output) {
  Cpp11UniformDice dice;

  for (int i = 0; i < number; ++i) {
    for (int j = 0; j < dim; ++j)
      output << dice.roll() << " ";
    output << std::endl;
  }
}

void main_s3_07() {
  std::ofstream file;
  file.open("data_s3_07_halton");

  printHaltonSequence(2, 100, file);

  file.close();

  file.open("data_s3_07_uniform");

  printUniformPoints(2, 100, file);

  file.close();
}


