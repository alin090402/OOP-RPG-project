//
// Created by ALIN on 26.02.2022.
//

#include <iostream>
#include <utility>
#include "Player.h"
#include "Monster.h"
#include "Utility.h"
void Player::Loot(Monster* monster) {
    coins += monster -> goldGiven;
    IncreaseExperience(monster->xpGiven);
    auto random = Utility::Random(monster->loot.size());
    for(unsigned int i = 0; i < monster->loot.size(); i++)
    {
        if(random[i] <= monster->loot[i].second)
            GetItem(monster->loot[i].first, 1);
    }
}

void Player::IncreaseExperience(int xp) {
    experience += xp;
    while(experience > lvl * lvl * 5)
    {
        experience -= lvl * lvl * 5;
        lvl++;
    }
}

void Player::GetItem(int id, int count) {
    for(auto slot: inventory)
        if(slot.first == id)
        {
            slot.second += count;
            return;
        }
}

Player::Player(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet,
               int weapon, int coins, int lvl, int experience, std::vector<std::pair<int, int>> inventory)
        : Entity(name, baseStats, chestplate, boots, ring, helmet, weapon), coins(coins), lvl(lvl),
          experience(experience), inventory(std::move(inventory)) {}
