//
// Created by ALIN on 26.02.2022.
//

#include "Item.h"

#include <utility>

std::vector<Item*> Item::itemList;
std::unordered_map<int, int> Item::id_to_pos;


Item::Item(int id, Item_type type, std::string name) : id(id), type(type), name(std::move(name)) {}

void ItemInit([[maybe_unused]]std::istream &is) {
    //TODO: de citit iteme din CSV si de creat vectorul de iteme;
}

const std::vector<Item *> &Item::getItemList() {
    return itemList;
}

const std::unordered_map<int, int> &Item::getIdToPos() {
    return id_to_pos;
}


Item::~Item() = default;
