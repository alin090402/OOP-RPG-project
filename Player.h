//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <vector>
#include <ostream>
#include "Entity.h"
class Item;
class Monster;
class Player: public Entity {
public:
    [[maybe_unused]] Player(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon,
           int coins, int lvl, int experience, std::vector<std::pair<int, int>> inventory);
    explicit Player(const std::string &inputFile);

    Player();

    void Loot(std::shared_ptr<Monster> monster);
    void IncreaseExperience(int xp);
    void GetItem(int id, int count);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    bool Craft(unsigned int ItemId);

    [[nodiscard]] const std::vector<std::pair<int, int>> &getInventory() const;

    bool Sell(unsigned int i, unsigned int count);

    [[nodiscard]] std::shared_ptr<Entity> clone()const override;

private:
    int coins = 0;
    int lvl = 1;
    int experience = 0;
    std::vector<std::pair<int,int> > inventory;


};


#endif //RPG_PLAYER_H
