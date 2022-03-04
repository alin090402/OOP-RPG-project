//
// Created by ALIN on 26.02.2022.
//

#include "Item.h"

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

Item::Item(const std::string &name, const std::string &description, int id, int quantity) : name(name),
                                                                                            description(description),
                                                                                            id(id),
                                                                                            quantity(quantity) {}
