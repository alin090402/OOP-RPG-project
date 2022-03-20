//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H


#include <vector>
#include <string>
#include "Entity.h"
#include "Player.h"


class Item;

class Enemy: public Entity {
private:
    Enemy( std::string name, int hp, int mana, int atk, int dex, int def, int xpGiven,
          std::vector<std::pair<Item *, float>> dropTable);

public:
    virtual ~Enemy();

private:
    friend class Player;
    friend class EnemyFactory;
    std::string name;
    int xp_given;
    std::vector<std::pair<Item*, float> > dropTable;
};



#endif //RPG_ENEMY_H
