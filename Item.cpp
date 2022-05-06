//
// Created by ALIN on 26.02.2022.
//

#include "Item.h"

#include <utility>
#include "Utility.h"
#include "Ingredient.h"
#include "Equipment.h"
#include "Sword.h"
#include "Bow.h"

std::vector<Item*> Item::itemList;
std::unordered_map<unsigned int, unsigned int> Item::id_to_pos;


Item::Item(int id, Item_type type, std::string name) : id(id), type(type), name(std::move(name)) {}

void Item::ItemInit(const std::string& file_name) {
    //TODO: de citit iteme din CSV si de creat vectorul de iteme;
    std::vector<std::string> lines = Utility::ReadFile(file_name);
    std::vector<std::string> data;
    for(auto& line : lines) {
        std::cout << line << std::endl;
        data = Utility::CSVParser(line);
        std::string &tip = data[0];
        int id = std::stoi(data[1]);
        std::string name = data[2];

        id_to_pos[id] = (unsigned int) Item::itemList.size();

        if(tip == "Ingredient")
        {
            int sell_price = std::stoi(data[3]);
            Item::itemList.push_back(new Ingredient(id, name, sell_price));
            continue;
        }
        Stats stats(std::stoi(data[3]), std::stoi(data[4]), std::stoi(data[5]), std::stoi(data[6]), std::stoi(data[7]));
        int price = std::stoi(data[8]);
        int required_level = std::stoi(data[9]);
        std::vector<std::pair<int, int>> recipe;
        for (unsigned int i = 10; i < data.size() - 1; i += 2) {
            int id_ = std::stoi(data[i]);
            int quantity = std::stoi(data[i + 1]);
            recipe.emplace_back(id_, quantity);
        }

        if(data[0] == "Chestplate")
        {
            Item::itemList.push_back(new Equipment(id, Item_type::Chestplate, name, stats, price, required_level, recipe));
            continue;
        }
        if(data[0] == "Helmet")
        {
            Item::itemList.push_back(new Equipment(id, Item_type::Helmet, name, stats, price, required_level, recipe));
            continue;
        }
        if(data[0] == "Boots")
        {
            Item::itemList.push_back(new Equipment(id, Item_type::Boots, name, stats, price, required_level, recipe));
            continue;
        }
        if(data[0] == "Ring")
        {
            Item::itemList.push_back(new Equipment(id, Item_type::Ring, name, stats, price, required_level, recipe));
            continue;
        }
        int min_dmg = std::stoi(data[data.size() - 3]);
        int max_dmg = std::stoi(data[data.size() - 2]);
        int specialManaCost = std::stoi(data[data.size() - 1]);
        recipe.pop_back();
        if(data[0] == "Sword")
        {
            Item::itemList.push_back(new Sword(id, Item_type::Sword, name, stats, price, required_level, recipe, min_dmg, max_dmg, specialManaCost));
            continue;
        }
        if(data[0] == "Bow")
        {
            Item::itemList.push_back(new Bow(id, Item_type::Bow, name, stats, price, required_level, recipe, min_dmg, max_dmg, specialManaCost));
            continue;
        }
        if(data[0] == "None")
        {
            Item::itemList.push_back(new Sword(id, Item_type::None, name, stats, price, required_level, recipe, min_dmg, max_dmg, specialManaCost));
            continue;
        }

    }

}

const std::vector<Item *> &Item::getItemList() {
    return itemList;
}

unsigned int Item::getIdToPos(unsigned int id) {
    return id_to_pos[id];
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
    item.Afisare(os);
    return os;
}

void Item::Afisare(std::ostream &os) const{
    os << "id: " << id << " name: " << name;
}

bool Item::Craftable() const {
    return false;
}

void Item::ShowRecipe(std::ostream &os) const{
    os << "No recipe for this item";
}


Item::~Item() = default;
