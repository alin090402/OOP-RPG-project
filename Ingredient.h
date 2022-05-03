//
// Created by ALIN on 14.04.2022.
//

#ifndef RPG_INGREDIENT_H
#define RPG_INGREDIENT_H
#include "Item.h"

class Ingredient: public Item{
public:
    Ingredient(int id, const std::string &name, int sellingPrice);

    [[nodiscard]] int getSellingPrice() const;


private:
    int selling_price;
    void Afisare(std::ostream &os)const override;

};


#endif //RPG_INGREDIENT_H
