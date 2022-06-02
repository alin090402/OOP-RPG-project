#include <iostream>
#include "Game.h"
#include "Monster.h"
#include "Exception.h"

int main() {
    try{
        Game::getGame().Init("data");
        Game::getGame().MainMenu();
    }
    catch (const FileException& e){
        std::cerr << "Error when retrieving data:" << e.what() << std::endl;
        return 1;
    }
    catch (const std::runtime_error& e){
        std::cerr << "Runtime error: " << e.what();
        return 1;
    }




    return 0;
}
