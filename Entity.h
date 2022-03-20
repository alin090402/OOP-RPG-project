//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_ENTITY_H
#define RPG_ENTITY_H


#include <ostream>

class Entity {
public:
    Entity(int hp, int mana, int atk, int dex, int def);
    Entity();
    Entity(const Entity& other);
    Entity& operator=(const Entity& other);

    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);

protected:
    int hp;
    int mana;
    int atk;
    int dex;
    int def;
};


#endif //RPG_ENTITY_H
