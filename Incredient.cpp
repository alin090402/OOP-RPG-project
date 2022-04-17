//
// Created by ALIN on 14.04.2022.
//

#include "Incredient.h"

int Incredient::getSellingPrice() const {
    return selling_price;
}

Incredient::Incredient(int id, const std::string &name, int sellingPrice) : Item(id, Item_type::Incredient, name),
                                                                                            selling_price(
                                                                                                    sellingPrice) {}
