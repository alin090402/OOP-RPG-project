//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <vector>
#include <ostream>
#include "Entity.h"
class Item;
class Monster;
class Player: public Entity {
public:
    Player(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon,
           int coins, int lvl, int experience, std::vector<std::pair<int, int>> inventory);
    explicit Player(const std::string &inputFile);

    void Loot(Monster* monster);
    void IncreaseExperience(int xp);
    void GetItem(int id, int count);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    bool Craft(unsigned int ItemId);

private:
    int coins;
    int lvl;
    int experience;
    std::vector<std::pair<int,int> > inventory;


};


#endif //RPG_PLAYER_H
