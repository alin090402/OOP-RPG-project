//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_UTILITY_H
#define RPG_UTILITY_H


#include <vector>

class Utility {
    public:
    static void Init();
    static std::vector<double> Random(int count); // return a float number between 0 and 1
};


#endif //RPG_UTILITY_H
