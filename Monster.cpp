//
// Created by ALIN on 17.04.2022.
//

#include "Monster.h"

#include <utility>

Monster::Monster(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet,
                 int weapon, int xpGiven, int goldGiven, std::vector<std::pair<int, double>> loot) : Entity(name,
                                                                                                                  baseStats,
                                                                                                                  chestplate,
                                                                                                                  boots,
                                                                                                                  ring,
                                                                                                                  helmet,
                                                                                                                  weapon),
                                                                                                           xpGiven(xpGiven),
                                                                                                           goldGiven(
                                                                                                                   goldGiven),
                                                                                                           loot(std::move(loot)) {}
