//
// Created by ALIN on 14.04.2022.
//

#include "Equipment.h"

const std::vector<std::pair<int, int>> &Equipment::getRecipe() const {
    return recipe;
}

Equipment::Equipment(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price,
                     const std::vector<std::pair<int, int>> &recipe, int requiredLevel) : Item(id, type, name),
                                                                                          bonus_stats(bonusStats),
                                                                                          price(price), recipe(recipe),
                                                                                          requiredLevel(
                                                                                                  requiredLevel) {}
