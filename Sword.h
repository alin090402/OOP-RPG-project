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
public:
    ~Sword() override;

    [[nodiscard]] std::shared_ptr<Item> clone()const override;

private:
    std::pair<int, double> LightAttack(std::shared_ptr<Entity> entity) override;
    std::pair<int, double> MediumAttack(std::shared_ptr<Entity> entity) override;
    std::pair<int, double> HeavyAttack(std::shared_ptr<Entity> entity) override;
    std::pair<int, double> SpecialAttack(std::shared_ptr<Entity> entity) override;

};


#endif //RPG_SWORD_H
