//
// Created by ALIN on 02.03.2022.
//

#ifndef RPG_ENEMYFACTORY_H
#define RPG_ENEMYFACTORY_H


#include <vector>
#include "Enemy.h"

class EnemyFactory: public Entities{
    friend std::ostream& operator<<(std::ostream& file, const EnemyFactory& enemyFactory);
    int xp_given;
    std::string name;
    std::vector<std::pair<Item*, float> > dropTable;
public:
    static std::vector< EnemyFactory* > EnemyTypes;
    EnemyFactory(std::string name, int hp, int mana, int atk, int dex, int def, int xpGiven,
                 std::vector<std::pair<Item *, float>> dropTable);

    Enemy* CreateEnemy();
    static void init();
    static void Finish();

};



#endif //RPG_ENEMYFACTORY_H
