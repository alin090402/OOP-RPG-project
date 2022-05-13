//
// Created by ALIN on 16.04.2022.
//

#include "Sword.h"
#include "Utility.h"


std::pair<int, double> Sword::LightAttack(std::shared_ptr<Entity> entity) {

    return {minDamage + entity->stats().getAtk() * 2, 1 - Utility::pow(0.8, entity->stats().getDex())};
}

std::pair<int, double> Sword::MediumAttack(std::shared_ptr<Entity> entity) {
    return {Utility::Random(minDamage, maxDamage) + entity->stats().getAtk() * 2, 1 - Utility::pow(0.88, entity->stats().getDex())};
}

std::pair<int, double> Sword::HeavyAttack(std::shared_ptr<Entity> entity) {
    return {maxDamage + entity->stats().getAtk() * 2, 1 - Utility::pow(0.93, entity->stats().getDex())};
}

std::pair<int, double> Sword::SpecialAttack(std::shared_ptr<Entity> entity) {
    int mana = entity->getCurrentMp();
    //std::cout << "mana:" << mana << " " << specialManaCost << std::endl;
    if(mana < specialManaCost) {
        entity->UseMana(mana);
        return {(maxDamage + entity->stats().getAtk() * 2) * (1 +  1.00 * mana / specialManaCost) ,  1.00f * mana / specialManaCost}; // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    entity->UseMana(specialManaCost);
    return {(maxDamage + entity->stats().getAtk() * 2), 1};
}

Sword::Sword(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
             const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage, int specialManaCost) : Weapon(id, type, name,
                                                                                                    bonusStats, price,
                                                                                                    requiredLevel,
                                                                                                    recipe, minDamage,
                                                                                                    maxDamage, specialManaCost) {}

std::shared_ptr<Item> Sword::clone() const {
    return std::make_shared<Sword>(*this);
}

Sword::~Sword() = default;
