#include "mainIncludes.h"
#include "defines.h"

#include <iostream>

int main(){
#ifdef SHEET1
  std::cout << "Starting sheet 1 task 3..." << std::endl;
  main3();
  std::cout << "Starting sheet 1 task 6..." << std::endl;
  main6();
  std::cout << "Starting sheet 1 task 9..." << std::endl;
  main9();
  std::cout << "Starting sheet 1 task 10..." << std::endl;
  main10();
#endif
#ifdef SHEET2
  std::cout << "Starting sheet 2 task 1..." << std::endl;
  main_s2_01();
  std::cout << "Starting sheet 2 task 2..." << std::endl;
  main_s2_02();
  std::cout << "Starting sheet 2 task 4..." << std::endl;
  main_s2_04();
  std::cout << "Starting sheet 2 task 9..." << std::endl;
  main_s2_09();
  std::cout << "Starting sheet 2 task 10..." << std::endl;
  main_s2_10();
#endif
#ifdef SHEET3
  std::cout << "Starting sheet 3 task 3..." << std::endl;
  main_s3_03();
  std::cout << "Starting sheet 3 task 4..." << std::endl;
  main_s3_04();
  std::cout << "Starting sheet 3 task 5..." << std::endl;
  main_s3_05();
  std::cout << "Starting sheet 3 task 7..." << std::endl;
  main_s3_07();
  std::cout << "Starting sheet 3 task 9..." << std::endl;
  main_s3_09();
  std::cout << "Starting sheet 3 task 11..." << std::endl;
  main_s3_11();
  std::cout << "Starting sheet 3 task 12..." << std::endl;
  main_s3_12();
  std::cout << "Starting sheet 3 task 13..." << std::endl;
  main_s3_13();
  std::cout << "Starting sheet 3 task 15..." << std::endl;
  main_s3_15();
  std::cout << "Starting sheet 3 task 16..." << std::endl;
  main_s3_16();
  std::cout << "Starting sheet 3 task 17..." << std::endl;
  main_s3_17();
#endif
#ifdef SHEET4
  std::cout << "Starting sheet 4 task 1..." << std::endl;
  main_s4_02();
#endif
#ifdef SHEET5
#endif
  std::cout << "Over and out." << std::endl << std::endl << std::endl;
  return 0;
}
