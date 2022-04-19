//
// Created by ALIN on 04.03.2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Game.h"

Game::Game(const std::string& dirr_name) : player("Alin", Stats(100,50,10,5,10), 0, 0, 0, 0, 0, 0, 1, 0, std::vector<std::pair<int,int> >())
{
    InitPlayer(dirr_name + "/player.txt");
    //InitItems(dirr_name + "/items.txt");
    //InitMonsters(dirr_name + "/monsters.txt");


}
void Game::InitPlayer(const std::string& filename)
{
    char s[500];
    std::ifstream  fin(filename);
    fin.getline(s, 500);
    //TODO: citeste playerul din csv
}
void CSVParser(const std::string& filename, std::vector<std::pair<int,int> >& v) {
    char s[500];
    std::ifstream fin(filename);
    fin.getline(s, 500);
    while(fin.getline(s, 500)) {
        std::stringstream ss(s);
        std::string item;
        std::vector<std::string> tokens;
        while(std::getline(ss, item, ',')) {
            tokens.push_back(item);
        }
        v.emplace_back(std::stoi(tokens[0]), std::stoi(tokens[1]));
    }
}