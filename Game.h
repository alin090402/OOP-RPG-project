//
// Created by ALIN on 04.03.2022.
//

#ifndef RPG_GAME_H
#define RPG_GAME_H


#include "Player.h"

class Game {
public:
    Game(const std::string& dirr_name);

private:
   Player player;
   void InitPlayer(const std::string& filename);

};

#endif //RPG_GAME_H
