//
// Created by ALIN on 02.06.2022.
//

#include "RecordAttack.h"

#include <utility>


void RecordAttack::Afisare(std::ostream &ostream) const {
    ostream << name << " hit " << enemy_name << " for " << dmg << " damage, leaving him at " << enemy_hp << " HP\n";
}

RecordAttack::RecordAttack(std::string name, std::string enemyName, int enemyHp, int dmg) : name(std::move(name)),
                                                                                            enemy_name(std::move(
                                                                                                                enemyName)),
                                                                                            enemy_hp(
                                                                                                                enemyHp),
                                                                                            dmg(dmg) {}


RecordAttack::RecordAttack() = default;
