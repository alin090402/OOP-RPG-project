//
// Created by ALIN on 16.04.2022.
//

#include "Sword.h"

//TODO: implement attack formulas

std::pair<int, float> Sword::LightAttack() {
    return {};
}

std::pair<int, float> Sword::MediumAttack() {
    return {};
}

std::pair<int, float> Sword::HeavyAttack() {
    return {};
}

std::pair<int, float> Sword::SpecialAttack() {
    return {};
}

Sword::Sword(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
             const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage) : Weapon(id, type, name,
                                                                                                    bonusStats, price,
                                                                                                    requiredLevel,
                                                                                                    recipe, minDamage,
                                                                                                    maxDamage) {}
