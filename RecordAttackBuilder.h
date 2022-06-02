//
// Created by ALIN on 02.06.2022.
//

#ifndef RPG_RECORDATTACKBUILDER_H
#define RPG_RECORDATTACKBUILDER_H


#include "RecordAttack.h"

class RecordAttackBuilder {
private:
    RecordAttack recordAttack;
public:
    RecordAttackBuilder& Name(std::string name);
    RecordAttackBuilder& EnemyName(std::string name);
    RecordAttackBuilder& Damage(int dmg);
    RecordAttackBuilder& EnemyHP(int hp);
    RecordAttack build() const;


    RecordAttackBuilder();
};


#endif //RPG_RECORDATTACKBUILDER_H
