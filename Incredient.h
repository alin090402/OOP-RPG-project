//
// Created by ALIN on 14.04.2022.
//

#ifndef RPG_INCREDIENT_H
#define RPG_INCREDIENT_H
#include "Item.h"

class Incredient: public Item{
public:
    Incredient(int id, const std::string &name, int sellingPrice);

    [[nodiscard]] int getSellingPrice() const;

private:
    int selling_price;
};


#endif //RPG_INCREDIENT_H
