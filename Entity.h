//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_ENTITY_H
#define RPG_ENTITY_H


#include <ostream>
#include <vector>
#include "Stats.h"
#include "Attack_type.h"

class Entity {


protected:
    std::string name;
    Stats base_stats;
    int currentHP;
    int currentMP;
private:
    [[nodiscard]] std::vector<int> equipments() const;

protected:
    int chestplate;
    int boots;
    int ring;
    int helmet;
    int weapon;

public:
    Entity(std::string name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon);

    Entity();

    void Heal();

    void UseMana(int mana);

    void Attack(Entity* enemy, Attack_type attackType);
    [[nodiscard]] Stats stats() const;

    [[maybe_unused]] [[nodiscard]] bool isAlive() const;

    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);

    [[nodiscard]] const std::string &getName() const;

    int getCurrentHp() const;

    int getWeapon() const;

    int getCurrentMp() const;


};


#endif //RPG_ENTITY_H
