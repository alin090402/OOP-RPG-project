//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_ITEM_H
#define RPG_ITEM_H


#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

enum class Item_type {Chestplate, Boots, Ring, Helmet, Ingredient, Sword, Bow, None};

 class Item {
 public:
     Item(int id, Item_type type, std::string name);


     static void ItemInit(const std::string& file_name);

     [[nodiscard]]virtual std::shared_ptr<Item> clone() const = 0;

     virtual ~Item();

     [[nodiscard]] virtual bool Craftable() const;

     [[nodiscard]] virtual bool Sellable() const;


     virtual void ShowRecipe(std::ostream &os) const;

     static const std::vector<Item *> &getItemList();

     [[nodiscard]] static unsigned int getIdToPos(unsigned int id);

     friend std::ostream &operator<<(std::ostream &os, const Item &item);

     [[nodiscard]] const std::string &getName() const;

     static void reset();

 protected:
     int id;
     Item_type type;
     std::string name;
     virtual void Afisare(std::ostream &os) const;
 private:
     static std::vector<Item*> itemList;

 private:
     static std::unordered_map<unsigned int, unsigned int> id_to_pos;

 };


#endif //RPG_ITEM_H
