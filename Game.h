//
// Created by ALIN on 04.03.2022.
//

#ifndef RPG_GAME_H
#define RPG_GAME_H


#include "Player.h"

class Game {
public:
    explicit Game(const std::string& dirr_name);
    void MainMenu();
private:

    Player player;
    void Fight(Monster monster);
    void FightMenu();

    void ShopMenu();

    void Save();

    void Load();

    void Craft();

    void Sell();
};

#endif //RPG_GAME_H
