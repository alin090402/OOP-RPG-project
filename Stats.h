//
// Created by ALIN on 14.04.2022.
//

#ifndef RPG_STATS_H
#define RPG_STATS_H


#include <string>
#include <ostream>

struct Stats {
    Stats(int hp, int mana, int atk, int def, int dex);
    Stats();

    //friend std::ostream &operator<<(std::ostream &os, const Stats &stats);
    friend Stats operator+(const Stats &a, const Stats &b);

    int hp;
    int mana;
    int atk;
    int def;
    int dex;
};


#endif //RPG_STATS_H
