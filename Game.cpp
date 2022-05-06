//
// Created by ALIN on 04.03.2022.
//

#include <iostream>
#include "Game.h"
#include "Item.h"
#include "Player.h"
#include "Monster.h"

Game::Game(const std::string& dirr_name) : player("Alin", Stats(100,50,10,5,10), 0, 0, 0, 0, 0, 0, 1, 0, std::vector<std::pair<int,int> >())
{
    Item::ItemInit(dirr_name + "/items.txt");
    Monster::MonsterInit(dirr_name + "/monsters.txt");
    player = Player(dirr_name + "/player.txt");
}

void Game::MainMenu() {
    bool end = false;
    while(!end)
    {
        std::cout << player << "\n";
        std::cout << "Welcome to the game!\n";
        std::cout << "1. Fight\n";
        std::cout << "2. Shop\n";
        std::cout << "3. Save\n";
        std::cout << "4. Load\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                FightMenu();
                break;
            case 2:
                ShopMenu();
                break;
            case 3:
                Save();
                break;
            case 4:
                Load();
                break;
            case 5:
                std::cout << "Goodbye!\n";
                end = true;
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    }


}

void Game::FightMenu() {
    while(true)
    {
        std::cout << "1. Exit\n";
        for(unsigned int i = 0; i < Monster::getMonsterList().size(); i++)
            std::cout << i+2 << ". " << Monster::getMonsterList()[i] << "\n";
        std::cout << "Enter your choice: ";
        unsigned int choice;
        std::cin >> choice;
        if(choice == 1) {
            break;
        }
        else if(choice >= 2 && choice <= Monster::getMonsterList().size()+1) {
            Fight(Monster::getMonsterList()[choice-2]);
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }



}

void Game::Fight(Monster monster) {
    std::cout << "You are fighting " << monster.getName() << "\n";
    player.Heal();
    monster.Heal();
    while(player.isAlive() && monster.isAlive())
    {
        std::cout << "your hp: " << player.getCurrentHp() << "     enemy hp: " << monster.getCurrentHp() << "\n";
        std::cout << "1.Light Attack\n";
        std::cout << "2.Medium Attack\n";
        std::cout << "3.Heavy Attack\n";
        std::cout << "4.Special Attack\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                player.Attack(&monster, Attack_type::Light_Attack);
                break;
            case 2:
                player.Attack(&monster, Attack_type::Medium_Attack);
                break;
            case 3:
                player.Attack(&monster, Attack_type::Heavy_Attack);
                break;
            case 4:
                player.Attack(&monster, Attack_type::Special_Attack);
                break;
            default:
                std::cout << "Invalid choice!\n";
                continue;
        }
        if(monster.isAlive())
            monster.Attack(&player, Attack_type::Medium_Attack);
    }
    if(player.isAlive())
        player.Loot(&monster);
    else
        std::cout << "You died!\n";
}

void Game::ShopMenu() {
    while(true)
    {
        std::cout << "SHOP\n";
        std::cout << "1. Craft\n";
        std::cout << "2. Sell\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::string choice_;
        std::cin >> choice_;
        int choice;
        try
        {
            choice = std::stoi(choice_);
        }
        catch (std::runtime_error &err){
            std::cout << "Invalid choice!\n";
            continue;
        }
        switch (choice)
        {
            case 1:
                Craft();
                break;
            case 2:
                Sell();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice!\n";
                continue;


        }
    }


}

void Game::Save() {

}

void Game::Load() {

}

void Game::Craft() {

    while(true)
    {
        std::cout << "Crafting menu\n";
        std::cout << "1. Exit\n";

        for(unsigned int i = 0; i < Item::getItemList().size(); i++)
            if(Item::getItemList()[i]->Craftable()) {
                std::cout << i + 2 << ". ";
                Item::getItemList()[i]->ShowRecipe(std::cout);
                std::cout << "\n";
            }
        std::cout << "Enter your choice: ";
        std::string choice_;
        std::cin >> choice_;
        unsigned int choice;
        try
        {
            choice = std::stoi(choice_);
        }
        catch (std::runtime_error &err){
            std::cout << "Invalid choice!\n";
            continue;
        }
        if(choice == 1)
            return;
        if(choice < 2 || choice > Item::getItemList().size() + 1)
        {
            std::cout << "Invalid choice!\n";
            continue;
        }
        if(!Item::getItemList()[choice - 2]->Craftable())
        {
            std::cout << "You can't craft this item!\n";
            continue;
        }
        if(!player.Craft(choice - 2))
        {
            std::cout << "You don't have enough materials!\n";
            continue;
        }


    }

}

void Game::Sell() {

}

Game::~Game() {
    for(auto item : Item::getItemList())
        delete item;



}

