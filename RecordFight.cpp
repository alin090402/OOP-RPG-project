//
// Created by ALIN on 04.06.2022.
//

#include "RecordFight.h"
#include "Item.h"
std::ostream &operator<<(std::ostream &os, const RecordFight &fights) {
    fights.Afisare(os);
    return os;
}

RecordFight::RecordFight(const std::string &name, const std::string &nameEnemy, int xp, int gold,
                           const std::vector<std::pair<int, int>> &loot) : name(name), name_enemy(nameEnemy), xp(xp),
                                                                           gold(gold), loot(loot) {}

void RecordFight::Afisare(std::ostream &ostream) const {
    ostream << name << " killed " << name_enemy << " and got ";
    ostream << "xp: " << xp;
    ostream << " gold: " << gold;
    for(auto &item : loot) {
        ostream << "  " << Item::getItemList()[Item::getIdToPos(item.first)]->getName() << " x" << item.second;
    }
}

RecordFight::RecordFight() = default;
