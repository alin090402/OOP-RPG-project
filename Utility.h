//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_UTILITY_H
#define RPG_UTILITY_H


#include <vector>

class Utility {
    public:
    static void Init();
    static std::vector<float> Random(int count); // return an float number between 0 and 1
};


#endif //RPG_UTILITY_H
