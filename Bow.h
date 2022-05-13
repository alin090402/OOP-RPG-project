//
// Created by ALIN on 16.04.2022.
//

#ifndef RPG_BOW_H
#define RPG_BOW_H
#include "Weapon.h"

class Bow: public Weapon{
public:
    Bow(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
        const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage, int specialManaCost);

    ~Bow() override;

    [[nodiscard]] std::shared_ptr<Item> clone()const override;

private:
    std::pair<int, double> LightAttack(std::shared_ptr<Entity> entity) override;
    std::pair<int, double> MediumAttack(std::shared_ptr<Entity> entity) override;
    std::pair<int, double> HeavyAttack(std::shared_ptr<Entity> entity) override;
    std::pair<int, double> SpecialAttack(std::shared_ptr<Entity> entity) override;

};


#endif //RPG_BOW_H
