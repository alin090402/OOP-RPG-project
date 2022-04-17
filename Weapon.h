//
// Created by ALIN on 16.04.2022.
//

#ifndef RPG_WEAPON_H
#define RPG_WEAPON_H
#include "Equipment.h"


class Weapon: public Equipment{
    int minDamage;
    int maxDamage;
    int price;
    virtual std::pair<int,float> LightAttack() = 0; // returns the damage and the hit change
    virtual std::pair<int,float> MediumAttack() = 0;
    virtual std::pair<int,float> HeavyAttack() = 0;
    virtual std::pair<int,float> SpecialAttack() = 0;
};


#endif //RPG_WEAPON_H
