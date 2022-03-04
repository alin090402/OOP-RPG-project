//
// Created by ALIN on 04.03.2022.
//

#include "Game.h"

Player Game::player;

void Game::Init()
{
    EnemyFactory::init();
    Entities stats(100, 10, 10, 2, 2);
    player = Player(stats);
}

void Game::Menu() {
    system("CLS");

}
