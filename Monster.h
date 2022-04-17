//
// Created by ALIN on 17.04.2022.
//

#ifndef RPG_MONSTER_H
#define RPG_MONSTER_H

#include "Entity.h"
//TODO: oare pot adauga functia loot fara adauga headerul playerului
#include "Player.h"


class Monster :public Entity{
public:
    Monster(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet,
            int weapon, int xpGiven, int goldGiven, std::vector<std::pair<int, double>> loot);
    friend void Player::Loot(Monster* monster);
private:
    int xpGiven;
    int goldGiven;
    std::vector<std::pair<int, double> >loot; //id item , changeToDrop

};


#endif //RPG_MONSTER_H
