//
// Created by ALIN on 26.02.2022.
//

#include "Item.h"

#include <utility>

int Item::UseItem(int quantity_)
{
    if(quantity < quantity_)
    {
        std::cout << "Nu ai destule iteme\n";
        return -1; // cod nu ai destule iteme
    }
    quantity -= quantity_;
    if(quantity == 0) {
        delete this;
        return -2; // cod ai ramas cu 0 iteme
    }
    return 0; // totul o mers bine
}

void Item::getItem(int quantity_)
{
    quantity += quantity_;
}

Item::Item(std::string name, std::string description, int id, int quantity) : name(std::move(name)),
                                                                                            description(std::move(description)),
                                                                                            id(id),
                                                                                            quantity(quantity) {}

int Item::getId() const {
    return id;
}
