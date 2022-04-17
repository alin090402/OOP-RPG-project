//
// Created by ALIN on 14.04.2022.
//

#ifndef RPG_EQUIPMENT_H
#define RPG_EQUIPMENT_H
#include "Item.h"
#include "Stats.h"
#include "Entity.h"

class Equipment : public Item{
public:
    Equipment(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price,
              const std::vector<std::pair<int, int>> &recipe, int requiredLevel);

    [[nodiscard]] const std::vector<std::pair<int, int>> &getRecipe() const;
    friend Stats Entity::stats() const;
private:
    Stats bonus_stats;
    int price;
    std::vector<std::pair<int, int> >recipe; // id, quantity
    int requiredLevel;
};


#endif //RPG_EQUIPMENT_H
