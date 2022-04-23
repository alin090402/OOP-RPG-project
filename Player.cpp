//
// Created by ALIN on 26.02.2022.
//

#include <iostream>
#include <utility>
#include "Player.h"
#include "Monster.h"
#include "Utility.h"

void Player::Loot(Monster* monster) {
    coins += monster -> getGoldGiven();
    IncreaseExperience(monster->getXpGiven());
    auto random = Utility::Random(monster->getLoot().size());
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
    for(auto &slot: inventory)
        if(slot.first == id)
        {
            slot.second += count;
            return;
        }
    inventory.emplace_back(id, count);
}

Player::Player(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet,
               int weapon, int coins, int lvl, int experience, std::vector<std::pair<int, int>> inventory)
        : Entity(name, baseStats, chestplate, boots, ring, helmet, weapon), coins(coins), lvl(lvl),
          experience(experience), inventory(std::move(inventory)) {}

Player::Player(const std::string &inputFile) {
    try {
        std::vector<std::string> lines = Utility::ReadFile(inputFile);
        std::vector<std::string> data = Utility::CSVParser(lines[0]);

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
    catch(std::exception &e) {
        std::cerr << "Obiectul Player nu a putut fi format" << e.what() << std::endl;
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

