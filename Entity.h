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

private:
    std::string name;
    Stats base_stats;
    int currentHP;
    [[nodiscard]] std::vector<int> equipments() const;

protected:
    int chestplate;
    int boots;
    int ring;
    int helmet;
    int weapon;

public:
    Entity(std::string name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon);
    void Attack(Entity* enemy, Attack_type attackType);
    [[nodiscard]] Stats stats() const;

    [[maybe_unused]] [[nodiscard]] bool isAlive() const;


};


#endif //RPG_ENTITY_H
