//
// Created by ALIN on 02.03.2022.
//

#include "EnemyFactory.h"

#include <utility>
#include <istream>

std::vector<EnemyFactory*> EnemyFactory::EnemyTypes;

Enemy *EnemyFactory::CreateEnemy() {
    auto* enemy = new Enemy(name, hp, mana, atk, dex, def, xp_given, dropTable);
    return enemy;
}
void EnemyFactory::init()
{
    EnemyTypes.push_back(new EnemyFactory("Goblin", 100, 0, 5, 5, 5, 15,
                                          std::vector<std::pair<Item *, float> >()));
}

EnemyFactory::EnemyFactory(std::string name, int hp, int mana, int atk, int dex, int def, int xpGiven,
                           std::vector<std::pair<Item *, float>> dropTable) : Entity(hp, mana, atk, dex, def),
                                                                              xp_given(xpGiven),
                                                                              name(std::move(name)), dropTable(std::move(dropTable)) {}
std::ostream& operator<<(std::ostream& file, const EnemyFactory& enemyFactory) {
    file << enemyFactory.name << "(hp:" << enemyFactory.hp << ", atk:" << enemyFactory.atk << ")";
    return file;
}

void EnemyFactory::Finish() {
    for(auto enemy: EnemyFactory::EnemyTypes)
    {
        delete enemy;
        enemy = nullptr;
    }
}
