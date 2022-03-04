//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <vector>
#include "Entities.h"
class Enemy;
class Item;
class Player: public Entities {
public:
    explicit Player(Entities entities);
    void hit(Enemy* &enemy);
    Player();

private:
    friend class Enemy;
    void Kill(Enemy* &enemy);
    std::vector<Item* > Inventory;
    int lvl{};
    int experience{};


};


#endif //RPG_PLAYER_H
