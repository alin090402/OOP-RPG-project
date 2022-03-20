//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <vector>
#include "Entity.h"
class Enemy;
class Item;
class Player: public Entity {
public:
    explicit Player(Entity entities);
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
