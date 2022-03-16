//
// Created by ALIN on 04.03.2022.
//

#include <iostream>
#include "Game.h"

Player Game::player;

void Game::Init()
{
    EnemyFactory::init();
    Entities stats(100, 10, 10, 2, 2);
    player = Player(stats);
    Game::Menu();
}

void Game::Menu() {
    std::string option;
    std::cout << "1. Fight\n";
    std::cout <<"2. Shop\n";
    std:: cin >> option;
    if(option == "1")
        Game::Choose_Enemy();
}

void Game::Choose_Enemy() {
    std::string option;
    int i = 0;
    for(auto enemy: EnemyFactory::EnemyTypes)
        std::cout << ++i << ". " << *enemy << "\n";
    std::cin >> option;
    while(stoi(option) > (int) EnemyFactory::EnemyTypes.size())
        std::cin >> option;
    Enemy* enemy = EnemyFactory::EnemyTypes[std::stoi(option) - 1]->CreateEnemy();
    Fight(enemy);
}

void Game::Fight(Enemy* &enemy) {
    player.hit(enemy);
    player.hit(enemy);
    player.hit(enemy);
    delete enemy;
}
