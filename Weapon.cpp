//
// Created by ALIN on 16.04.2022.
//

#include "Weapon.h"

Weapon::Weapon(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
               const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage, int specialManaCost) :
                                                                                                        Equipment(id, type, name,
                                                                                                         bonusStats,
                                                                                                         price,
                                                                                                         requiredLevel,
                                                                                                         recipe),
                                                                                               minDamage(minDamage),
                                                                                               maxDamage(maxDamage),
                                                                                               specialManaCost(specialManaCost){}

void Weapon::Afisare(std::ostream &os) const{
    Equipment::Afisare(os);
    os << "Min damage: " << minDamage << std::endl;
    os << "Max damage: " << maxDamage << std::endl;
}

Weapon::~Weapon() = default;
