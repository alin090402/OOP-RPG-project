//
// Created by ALIN on 17.04.2022.
//

#ifndef RPG_MONSTER_H
#define RPG_MONSTER_H

#include <ostream>
#include "Entity.h"
//TODO: oare pot adauga functia loot fara adauga headerul playerului
#include "Player.h"


class Monster :public Entity{
public:
    Monster(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet,
            int weapon, int xpGiven, int goldGiven, std::vector<std::pair<int, double>> loot);
    friend void Player::Loot(Monster* monster);
    static void MonsterInit(const std::string& file_name);


    static const std::vector<Monster> &getMonsterList();

    friend std::ostream &operator<<(std::ostream &os, const Monster &monster);

private:
    int xpGiven;
    int goldGiven;
    std::vector<std::pair<int, double> >loot; //id item , changeToDrop
    static std::vector<Monster> monsterList;
};


#endif //RPG_MONSTER_H
