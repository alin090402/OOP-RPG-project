//
// Created by ALIN on 26.02.2022.
//

#include "Entity.h"

Entity::Entity(int hp, int mana, int atk, int dex, int def) : hp(hp), mana(mana), atk(atk), dex(dex), def(def) {}

Entity::Entity() : hp(0), mana(0), atk(0), dex(0), def(0){

}


Entity::Entity(const Entity &other): hp(other.hp), mana(other.mana), atk(other.atk), dex(other.dex), def(other.def){

}

Entity &Entity::operator = (const Entity &other) {
    this->hp = other.hp;
    this->mana = other.mana;
    this->atk = other.atk;
    this->dex = other.dex;
    this->def = other.def;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "hp: " << entity.hp << " mana: " << entity.mana << " atk: " << entity.atk << " dex: " << entity.dex
       << " def: " << entity.def;
    return os;
}


