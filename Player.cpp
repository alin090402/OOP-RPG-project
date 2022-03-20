//
// Created by ALIN on 26.02.2022.
//

#include <iostream>
#include "Player.h"
#include "Enemy.h"

Player::Player(Entity entities) : Entity(entities), Inventory(), lvl(0), experience(0) {
}

void Player::Kill(Enemy* &enemy) {
    std::cout << enemy->name <<" has been killed.\n";
    experience += enemy->xp_given;
    while(experience > lvl * lvl)
    {
        ++lvl;
        experience -= lvl * lvl;
    }
    /*for(auto drop: enemy->dropTable);
    {

    }*/
    delete enemy;
    enemy = nullptr;

}

void Player::hit(Enemy* &enemy) {
    if(enemy == nullptr) {
        std::cout << "Ce faci ma? E deja mort.\n";
        return;
    }
    enemy -> hp -= (atk);
    std::cout<<"You hit " << enemy-> name << " with " << atk << " damage. Enemy hp: " << enemy->hp << "\n";
    if(enemy -> hp <= 0)
        Kill(enemy);

}

Player::Player() = default;