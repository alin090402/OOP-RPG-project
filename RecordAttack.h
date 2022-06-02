//
// Created by ALIN on 02.06.2022.
//

#ifndef RPG_RECORDATTACK_H
#define RPG_RECORDATTACK_H


#include "Record.h"

class RecordAttack: public Record{
public:
    RecordAttack(std::string name, std::string enemyName, int enemyHp, int dmg);

public:

    RecordAttack();


private:
    std::string name;
    std::string enemy_name;
    int enemy_hp{};
    int dmg{};
    void Afisare(std::ostream &ostream) const override;

    friend class RecordAttackBuilder;

};


#endif //RPG_RECORDATTACK_H
