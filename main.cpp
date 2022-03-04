#include <iostream>

#include "Player.h"
#include "Utility.h"
#include "EnemyFactory.h"
int main() {

    EnemyFactory::init();
    Enemy* enemy = EnemyFactory::EnemyTypes[0]->CreateEnemy();
    Entities stats(10, 10, 1000, 2, 2);
    Player Jucator(stats);
    Jucator.hit(enemy);
    Jucator.hit(enemy);
    for(auto valoare: Utility::Random(10))
        std::cout << valoare << " ";
    std::cout << "\n";
    for(auto valoare: Utility::Random(10))
        std::cout << valoare << " ";

    return 0;
}
