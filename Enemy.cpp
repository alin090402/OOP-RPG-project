//
// Created by ALIN on 26.02.2022.
//

#include "Enemy.h"

#include <utility>
Enemy::~Enemy() =default;

Enemy::Enemy( std::string name,int hp, int mana, int atk, int dex, int def, int xpGiven,
             std::vector<std::pair<Item *, float>> dropTable) : Entities(hp, mana, atk, dex, def),
                                                                                         xp_given(xpGiven), dropTable(std::move(dropTable)),
                                                                                         name(std::move(name)) {}
