//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_ITEM_H
#define RPG_ITEM_H


#include <string>
#include <iostream>

class Item {
    std::string name;
    std::string description;
    int id;
    int quantity;

public:
    Item(const std::string &name, const std::string &description, int id, int quantity);

private:
    int UseItem(int quantity_);

    void getItem(int q);


};


#endif //RPG_ITEM_H
