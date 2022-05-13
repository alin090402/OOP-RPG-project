//
// Created by ALIN on 14.04.2022.
//

#include "Ingredient.h"

int Ingredient::getSellingPrice() const {
    return selling_price;
}

Ingredient::Ingredient(int id, const std::string &name, int sellingPrice) : Item(id, Item_type::Ingredient, name),
                                                                            selling_price(
                                                                                                    sellingPrice) {}

void Ingredient::Afisare(std::ostream &os) const{
    os << "Ingredient: name:" << name << " id:" << id << " selling_price:" << selling_price << std::endl;
}

bool Ingredient::Sellable() const {
    return true;
}

std::shared_ptr<Item> Ingredient::clone() const {
    return std::make_shared<Ingredient>(*this);
}

Ingredient::~Ingredient() = default;

