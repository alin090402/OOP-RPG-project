#include <iostream>
#include "Game.h"
#include "Monster.h"
#include "Exception.h"

int main() {
    try{
        Game game = Game("data");
        game.MainMenu();
    }
    catch (const FileException& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }




    return 0;
}
