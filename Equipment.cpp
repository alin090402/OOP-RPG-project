//
// Created by ALIN on 14.04.2022.
//

#include "Equipment.h"

#include <utility>

const std::vector<std::pair<int, int>> &Equipment::getRecipe() const {
    return recipe;
}

Equipment::Equipment(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
                     std::vector<std::pair<int, int>> recipe) : Item(id, type, name),
                                                                                          bonus_stats(bonusStats),
                                                                                          price(price),
                                                                                          requiredLevel(requiredLevel),
                                                                                          recipe(std::move(recipe)){}

void Equipment::Afisare(std::ostream &os) const{
    Item::Afisare(os);
    os << "Bonus stats: " << bonus_stats << std::endl;
    os << "Price: " << price << std::endl;
    os << "Required level: " << requiredLevel << std::endl;
    os << "Recipe: " << std::endl;
    ShowRecipe(os);
}

bool Equipment::Craftable() const {
    return true;
}

void Equipment::ShowRecipe(std::ostream &os) const {
    for(auto &i : recipe) {
        os<< Item::getItemList()[Item::getIdToPos(i.first)]->getName() << "x" << i.second << "\n";
    }
}

int Equipment::getRequiredLvl() const {
    return requiredLevel;
}

std::shared_ptr<Item> Equipment::clone() const {
    return std::make_shared<Equipment>(*this);
}

int Equipment::getGoldPrice() const {
    return price;
}

Equipment::~Equipment() = default;



