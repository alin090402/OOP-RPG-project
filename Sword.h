//
// Created by ALIN on 16.04.2022.
//

#ifndef RPG_SWORD_H
#define RPG_SWORD_H
#include "Weapon.h"

class Sword: public Weapon{
    std::pair<int, float> LightAttack() override;
    std::pair<int, float> MediumAttack() override;
    std::pair<int, float> HeavyAttack() override;
    std::pair<int, float> SpecialAttack() override;

};


#endif //RPG_SWORD_H
