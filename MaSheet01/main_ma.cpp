#include <iostream>

void task1();
void task2();
void task3();
void task4();

void main_master() {
    std::cout << "Running master sheet task 1..." << std::endl;
    task1();
    std::cout << "Running master sheet task 2..." << std::endl;
    task2();
    std::cout << "Running master sheet task 3..." << std::endl;
    task3();
    std::cout << "Running master sheet task 4..." << std::endl;
    task4();
}
