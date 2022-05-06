//
// Created by ALIN on 26.02.2022.
//

#include <iostream>
#include <utility>
#include "Player.h"
#include "Monster.h"
#include "Utility.h"
#include "Item.h"
#include "Equipment.h"
#include "Ingredient.h"

void Player::Loot(Monster* monster) {
    coins += monster -> getGoldGiven();
    IncreaseExperience(monster->getXpGiven());
    auto random = Utility::Random((unsigned int)monster->getLoot().size());
    for(unsigned int i = 0; i < monster->getLoot().size(); i++)
    {
        std::cout << "random" << random[i] << std::endl;
        if(random[i] <= monster->getLoot()[i].second)
            GetItem(monster->getLoot()[i].first, 1);
    }
}

void Player::IncreaseExperience(int xp) {
    experience += xp;
    while(experience > lvl * lvl * 5)
    {
        experience -= lvl * lvl * 5;
        lvl++;
    }
}

void Player::GetItem(int id, int count) {
    std:: cout << "got" << count << "x " << id << std::endl;
    auto slot = std::find_if(inventory.begin(), inventory.end(), [&](std::pair<int,int> item) { return item.first == id;});
    if(slot != inventory.end())
    {
        slot -> second += count;
        return;
    }
    inventory.emplace_back(id, count);
    /**for(auto &slot: inventory)

        if(slot.first == id)
        {
            slot.second += count;
            return;
        }*/

}

Player::Player(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet,
               int weapon, int coins, int lvl, int experience, std::vector<std::pair<int, int>> inventory)
        : Entity(name, baseStats, chestplate, boots, ring, helmet, weapon), coins(coins), lvl(lvl),
          experience(experience), inventory(std::move(inventory)) {}

Player::Player(const std::string &inputFile) {
        std::vector<std::string> lines = Utility::ReadFile(inputFile);
        if(lines.empty())
            throw std::runtime_error("there is no player in file");
        std::vector<std::string> data = Utility::CSVParser(lines[0]);

        if(data.size() < 14)
            throw std::runtime_error("not enough data in player file");

        name = data[0];
        base_stats = Stats(std::stoi(data[1]), std::stoi(data[2]), std::stoi(data[3]),
                           std::stoi(data[4]),std::stoi(data[5]));
        currentHP = base_stats.getHp();
        chestplate = std::stoi(data[6]);
        boots = std::stoi(data[7]);
        ring = std::stoi(data[8]);
        helmet = std::stoi(data[9]);
        weapon = std::stoi(data[10]);
        experience = std::stoi(data[11]);
        lvl = std::stoi(data[12]);
        coins = std::stoi(data[13]);
        for(unsigned int i = 14; i < data.size(); i += 2) {
            inventory.emplace_back(std::stoi(data[i]), std::stod(data[i + 1]));
        }

}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << static_cast<const Entity &>(player) << "\ncoins: " << player.coins << "\nlvl: " << player.lvl << "\nexperience: "
       << player.experience;
    std::cout << " \ninventory: ";

    for(auto item: player.inventory)
        os << "\n" << item.first << " " << item.second;

    return os;
}

bool Player::Craft(const unsigned int ItemId) {
    auto *equipment = dynamic_cast<Equipment*>(Item::getItemList()[Item::getIdToPos(ItemId)]);
    if(equipment == nullptr)
        return false;
    if(equipment -> getRequiredLvl() > lvl)
        return false;
    for(auto &ingredient : equipment -> getRecipe())
    {
        bool found = false;
        for(auto &item: inventory)
        {
            if(item.first == ingredient.first)
            {
                if(item.second >= ingredient.second)
                {
                    found = true;
                    break;
                }
            }
        }
        if(!found)
            return false;
    }
    for(auto &ingredient : equipment -> getRecipe())
    {
        auto slot = std::find_if(inventory.begin(), inventory.end(), [&](std::pair<int,int> item) { return item.first == ingredient.first;});
        if(slot != inventory.end())
        {
            slot -> second -= ingredient.second;
            if(slot -> second == 0)
                inventory.erase(slot);
        }
    }
    GetItem(ItemId, 1);
    return true;
}

const std::vector<std::pair<int, int>> &Player::getInventory() const {
    return inventory;
}

bool Player::Sell(unsigned int id, unsigned int count) {
    if(count == 0)
        return false;
    if(!Item::getItemList()[Item::getIdToPos(id)] -> Sellable())
        return false;
    for(auto &item: inventory)
    {
        if(item.first == (int) id)
        {
            if(item.second >= (int) count)
            {
                item.second -= (int)count;
                coins += (int)count * dynamic_cast<Ingredient*>(Item::getItemList()[Item::getIdToPos(id)]) -> getSellingPrice();
                return true;
            }
            else
            {
                coins += item.second * dynamic_cast<Ingredient*>(Item::getItemList()[Item::getIdToPos(id)]) -> getSellingPrice();
                item.second = 0;
                return true;
            }
        }
    }
    return false;
}

