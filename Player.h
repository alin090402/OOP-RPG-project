//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <vector>
#include "Entity.h"
class Item;
class Monster;
class Player: public Entity {
public:
    Player(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon,
           int coins, int lvl, int experience, std::vector<std::pair<int, int>> inventory);

    void Loot(Monster* monster);
    void IncreaseExperience(int xp);
    void GetItem(int id, int count);

private:
    int coins;
    int lvl;
    int experience;
    std::vector<std::pair<int,int> > inventory;


};


#endif //RPG_PLAYER_H
