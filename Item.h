//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_ITEM_H
#define RPG_ITEM_H


#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

enum class Item_type {Chestplate, Boots, Ring, Helmet, Incredient, Sword, Bow};

 class Item {
 public:
     Item(int id, Item_type type, std::string name);


     friend void ItemInit(std::istream &is);

     virtual ~Item();

     static const std::vector<Item *> &getItemList();

     static const std::unordered_map<int, int> &getIdToPos();


 private:
     int id;
     Item_type type;
     std::string name;
     static std::vector<Item*> itemList;
     static std::unordered_map<int, int> id_to_pos;

};


#endif //RPG_ITEM_H
