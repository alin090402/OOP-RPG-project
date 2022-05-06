//
// Created by ALIN on 16.04.2022.
//

#include "Sword.h"
#include "Utility.h"

//TODO: implement attack formulas

std::pair<int, float> Sword::LightAttack(Entity &entity) {

    return {minDamage + entity.stats().getAtk() * 2, 1 - Utility::pow(0.8, entity.stats().getDex())};
}

std::pair<int, float> Sword::MediumAttack(Entity &entity) {
    return {Utility::Random(minDamage, maxDamage) + entity.stats().getAtk() * 2, 1 - Utility::pow(0.88, entity.stats().getDex())};
}

std::pair<int, float> Sword::HeavyAttack(Entity &entity) {
    return {maxDamage + entity.stats().getAtk() * 2, 1 - Utility::pow(0.93, entity.stats().getDex())};
}

std::pair<int, float> Sword::SpecialAttack(Entity &entity) {
    int mana = entity.getCurrentMp();
    std::cout << "mana:" << mana << " " << specialManaCost << std::endl;
    if(mana < specialManaCost) {
        entity.UseMana(mana);
        return {(maxDamage + entity.stats().getAtk() * 2) * (1 +  1.00f * mana / specialManaCost) ,  1.00f * mana / specialManaCost}; // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    entity.UseMana(specialManaCost);
    return {(maxDamage + entity.stats().getAtk() * 2), 1};
}

Sword::Sword(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
             const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage, int specialManaCost) : Weapon(id, type, name,
                                                                                                    bonusStats, price,
                                                                                                    requiredLevel,
                                                                                                    recipe, minDamage,
                                                                                                    maxDamage, specialManaCost) {}
