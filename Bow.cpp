//
// Created by ALIN on 16.04.2022.
//

#include "Bow.h"
#include "Utility.h"

//TODO: implement attack formulas
std::pair<int, float> Bow::LightAttack(Entity &entity) {

    return {minDamage + entity.stats().getDex(), 1 - Utility::pow(0.9, entity.stats().getDex())};
}

std::pair<int, float> Bow::MediumAttack(Entity &entity) {
    return {Utility::Random(minDamage, maxDamage) + entity.stats().getDex(), 1 - Utility::pow(0.92, entity.stats().getDex())};
}

std::pair<int, float> Bow::HeavyAttack(Entity &entity) {
    return {maxDamage + entity.stats().getDex(), 1 - Utility::pow(0.95, entity.stats().getDex())};
}

std::pair<int, float> Bow::SpecialAttack(Entity &entity) {
    int mana = entity.getCurrentMp();
    if(mana < specialManaCost) {
        entity.UseMana(mana);
        return {maxDamage * (1 +  1.00f * mana / specialManaCost) , 1.00f * mana / specialManaCost}; // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    entity.UseMana(specialManaCost);
    return {maxDamage * 2, 1};
}

/// e posibil sa fac direct atribuirea la contructori?
Bow::Bow(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
         const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage, int specialManaCost) : Weapon(id, type, name,
                                                                                                bonusStats, price,
                                                                                                requiredLevel, recipe,
                                                                                                minDamage, maxDamage, specialManaCost) {}
