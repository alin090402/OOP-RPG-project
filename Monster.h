//
// Created by ALIN on 17.04.2022.
//

#ifndef RPG_MONSTER_H
#define RPG_MONSTER_H

#include <ostream>
#include "Entity.h"



class Monster :public Entity{
public:
    Monster(const std::string &name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet,
            int weapon, int xpGiven, int goldGiven, std::vector<std::pair<int, double>> loot);
    static void MonsterInit(const std::string& file_name);


    static const std::vector<Monster> &getMonsterList();

    friend std::ostream &operator<<(std::ostream &os, const Monster &monster);

    [[nodiscard]] int getXpGiven() const;

    [[nodiscard]] int getGoldGiven() const;

    [[nodiscard]] const std::vector<std::pair<int, double>> &getLoot() const;

    static void reset();

    std::shared_ptr<Entity> clone() const override;

    virtual ~Monster();

private:
    int xpGiven;
    int goldGiven;
    std::vector<std::pair<int, double> >loot; //id item , changeToDrop
    static std::vector<Monster> monsterList;
};


#endif //RPG_MONSTER_H
