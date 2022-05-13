//
// Created by ALIN on 17.04.2022.
//

#include "Monster.h"
#include "Utility.h"

#include <utility>
#include <iostream>

std::vector<Monster> Monster::monsterList;

Monster::Monster(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet,
                 int weapon, int xpGiven, int goldGiven, std::vector<std::pair<int, double>> loot) : Entity(name,
                                                                                                                  baseStats,
                                                                                                                  chestplate,
                                                                                                                  boots,
                                                                                                                  ring,
                                                                                                                  helmet,
                                                                                                                  weapon),
                                                                                                           xpGiven(xpGiven),
                                                                                                           goldGiven(
                                                                                                                   goldGiven),
                                                                                                           loot(std::move(loot)) {}

const std::vector<Monster> &Monster::getMonsterList() {
    return monsterList;
}

void Monster::MonsterInit(const std::string &file_name) {
    std::vector<std::string> lines = Utility::ReadFile(file_name);
    std::vector<std::string> data;
    for(const auto& line:lines) {
        if(line[0] == '#') continue;
        data = Utility::CSVParser(line);
        if(data.empty()) continue;
        if(data.size() < 13)
            throw std::runtime_error("Not enough data in monster file");
        std::string name = data[0];
        Stats stats = Stats(std::stoi(data[1]), std::stoi(data[2]), std::stoi(data[3]),
                            std::stoi(data[4]),std::stoi(data[5]));
        int chestplate = std::stoi(data[6]);
        int boots = std::stoi(data[7]);
        int ring = std::stoi(data[8]);
        int helmet = std::stoi(data[9]);
        int weapon = std::stoi(data[10]);
        int xpGiven = std::stoi(data[11]);
        int goldGiven = std::stoi(data[12]);
        std::vector<std::pair<int, double>> loot;
        for(unsigned int i = 13; i < data.size(); i += 2) {
            loot.emplace_back(std::stoi(data[i]), std::stod(data[i + 1]));
        }
        monsterList.emplace_back(name, stats, chestplate, boots, ring, helmet, weapon, xpGiven, goldGiven, std::move(loot));

    }

}

std::ostream &operator<<(std::ostream &os, const Monster &monster) {
    os << static_cast<const Entity &>(monster) << "\nxpGiven: " << monster.xpGiven << "\ngoldGiven: " << monster.goldGiven << "\n";
    os << " Loot: ";
    for(const auto& item:monster.loot) {
        os << " " << item.first << " " << item.second << "\n";
    }
    return os;
}

int Monster::getXpGiven() const {
    return xpGiven;
}

int Monster::getGoldGiven() const {
    return goldGiven;
}

const std::vector<std::pair<int, double>> &Monster::getLoot() const {
    return loot;
}

void Monster::reset() {
    monsterList.clear();
}

std::shared_ptr<Entity> Monster::clone() const {
    return std::make_shared<Monster>(*this);
}

Monster::~Monster() = default;
