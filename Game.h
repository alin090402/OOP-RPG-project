//
// Created by ALIN on 04.03.2022.
//

#ifndef RPG_GAME_H
#define RPG_GAME_H


#include "Player.h"
#include "EnemyFactory.h"

class Game {
    static Player player;

public:
    static void Init();


private:
    static void Menu();
    static void Fight(Enemy* &enemy);
    static void Choose_Enemy();

};


#endif //RPG_GAME_H
