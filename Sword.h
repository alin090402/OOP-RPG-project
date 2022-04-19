//
// Created by ALIN on 16.04.2022.
//

#ifndef RPG_SWORD_H
#define RPG_SWORD_H
#include "Weapon.h"

class Sword: public Weapon{
public:
    Sword(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
          const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage);

private:
    std::pair<int, float> LightAttack() override;
    std::pair<int, float> MediumAttack() override;
    std::pair<int, float> HeavyAttack() override;
    std::pair<int, float> SpecialAttack() override;

};


#endif //RPG_SWORD_H
