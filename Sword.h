//
// Created by ALIN on 16.04.2022.
//

#ifndef RPG_SWORD_H
#define RPG_SWORD_H
#include "Weapon.h"

class Sword: public Weapon{
public:
    Sword(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
          const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage, int specialManaCost);

private:
    std::pair<int, float> LightAttack(Entity &entity) override;
    std::pair<int, float> MediumAttack(Entity &entity) override;
    std::pair<int, float> HeavyAttack(Entity &entity) override;
    std::pair<int, float> SpecialAttack(Entity &entity) override;

};


#endif //RPG_SWORD_H
