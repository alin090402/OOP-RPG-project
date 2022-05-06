//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_UTILITY_H
#define RPG_UTILITY_H


#include <vector>

class Utility {
    public:
    static std::vector<std::string> CSVParser(const std::string& line);
    static std::vector<std::string> ReadFile(const std::string& fileName);
    static void Init();
    static int Random(int min, int max);
    static float Random();
    static float pow(float base, int exp);
    static std::vector<double> Random(unsigned int count); // return a float number between 0 and 1
};


#endif //RPG_UTILITY_H
