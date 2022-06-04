//
// Created by ALIN on 04.06.2022.
//

#ifndef RPG_RECORDFIGHT_H
#define RPG_RECORDFIGHT_H


#include <vector>
#include <ostream>
#include "Record.h"

class RecordFight: public Record {
public:
    RecordFight();

private:
    void Afisare(std::ostream &ostream) const override;

public:

    friend std::ostream &operator<<(std::ostream &os, const RecordFight &fights);

private:
    std::string name;
    std::string name_enemy;
    int xp;
    int gold;
public:
    RecordFight(const std::string &name, const std::string &nameEnemy, int xp, int gold,
                 const std::vector<std::pair<int, int>> &loot);

private:
    std::vector<std::pair<int,int> > loot;

};


#endif //RPG_RECORDFIGHT_H
