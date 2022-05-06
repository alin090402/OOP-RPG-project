//
// Created by ALIN on 26.02.2022.
//

#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include "Utility.h"
void Utility::Init()
{
    std::srand( (unsigned)std::time(nullptr) );

}

std::vector<std::string> Utility::CSVParser(const std::string& line)
{
    std::vector<std::string> values;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, ','))
    {
        values.push_back(item);
    }
    return values;
}

std::vector<double> Utility::Random(unsigned int count) {
    std::vector<double>v;

    for(unsigned int i = 0; i < count; i++)
        v.push_back((double) std::rand() / RAND_MAX);
    return v;
}

std::vector<std::string> Utility::ReadFile(const std::string &fileName) {
    std::vector<std::string> lines;
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

int Utility::Random(const int min, const int max) {
    return std::rand() % (max - min + 1) + min;
}



double Utility::pow(double base, int exp) {
    ///fast exponentiation
    double result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

double Utility::Random() {
    return (double) std::rand() / RAND_MAX;
}


