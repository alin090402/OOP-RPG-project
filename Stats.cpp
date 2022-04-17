//
// Created by ALIN on 14.04.2022.
//

#include "Stats.h"


Stats::Stats(int hp, int mana, int atk, int def, int dex) : hp(hp), mana(mana), atk(atk), def(def), dex(dex) {}

std::ostream &operator<<(std::ostream &os, const Stats &stats) {
    os << " hp: " << stats.hp << " mana: " << stats.mana << " atk: " << stats.atk << " def: "
       << stats.def << " dex: " << stats.dex;
    return os;
}

Stats::Stats(): hp(0), mana(0), atk(0), def(0), dex(0) {}

Stats operator+(const Stats &a, const Stats &b) {
    Stats answer;
    answer.hp = a.hp + b.hp;
    answer.mana = a.mana + b.mana;
    answer.atk = a.atk + b.atk;
    answer.def = a.def + b.def;
    answer.dex = a.dex + b.dex;
    return answer;
}
