//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_ENTITY_H
#define RPG_ENTITY_H


#include <ostream>
#include <vector>
#include <memory>
#include "Stats.h"
#include "Attack_type.h"

class Entity : public std::enable_shared_from_this<Entity>{


protected:
    std::string name;
    Stats base_stats = Stats(0, 0, 0, 0, 0);
    int currentHP{};
    int currentMP{};
    int chestplate{};
    int boots{};
    int ring{};
    int helmet{};
    int weapon{};

public:
    Entity(std::string name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon);

    Entity();

    [[nodiscard]]virtual std::shared_ptr<Entity> clone() const = 0;

    void Heal();

    void UseMana(int mana);

    void Attack(const std::shared_ptr<Entity>& enemy, Attack_type attackType);
    [[nodiscard]] Stats stats() const;

    [[nodiscard]] bool isAlive() const;

    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] int getCurrentHp() const;

    [[nodiscard]] int getCurrentMp() const;

    [[nodiscard]] std::vector<int> equipments() const;

    void ShowEquipment(std::ostream &os) const;
};


#endif //RPG_ENTITY_H
