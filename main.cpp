#include <iostream>
#include <fstream>
#include <sstream>
#include "Game.h"
#include "Utility.h"
#include "Item.h"
#include "Monster.h"

int main() {
    for(const auto& linie: Utility::ReadFile("date.in"))
    {
        for(const auto& cuvant: Utility::CSVParser(linie))
            std::cout << cuvant << " ";
        std::cout << "\n";
    }
    Item::ItemInit("items.txt");
    for(const auto& item:Item::getItemList())
        std::cout << *item<< "\n";
    Monster::MonsterInit("monsters.txt");
    for(const auto& monster:Monster::getMonsterList())
        std::cout << monster<< "\n";





    return 0;
}
