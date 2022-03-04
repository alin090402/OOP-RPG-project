//
// Created by ALIN on 26.02.2022.
//

#include <cstdlib>
#include <ctime>
#include "Utility.h"
void Utility::Init()
{
    std::srand( (unsigned)std::time(nullptr) );

}


std::vector<float> Utility::Random(int count) {
    std::vector<float>v;

    for(int i = 0; i < count; i++)
        v.push_back((float) std::rand()/RAND_MAX);
    return v;
}
