#include <iostream>

#include "Utility.h"
#include "Game.h"

int main() {
    Game::Init();
    EnemyFactory::Finish();

    return 0;
}
