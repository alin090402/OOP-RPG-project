//
// Created by ALIN on 02.06.2022.
//

#include "RecordAttackBuilder.h"
#include "Exception.h"

#include <utility>

RecordAttackBuilder &RecordAttackBuilder::Name(std::string name) {
    recordAttack.name = std::move(name);
    return *this;
}

RecordAttackBuilder &RecordAttackBuilder::EnemyName(std::string name) {
    recordAttack.enemy_name = std::move(name);
    return *this;
}

RecordAttackBuilder &RecordAttackBuilder::Damage(int dmg) {
    recordAttack.dmg = dmg;
    return *this;
}

RecordAttackBuilder &RecordAttackBuilder::EnemyHP(int hp) {
    recordAttack.enemy_hp = hp;
    return *this;
}

RecordAttack RecordAttackBuilder::build() const{
    if(recordAttack.name.empty())
        throw BuilderException("Name was not set in the recordFightBuilder");
    if(recordAttack.enemy_name.empty())
        throw BuilderException("Enemy name was not set in the recordFightBuilder");
    if(recordAttack.dmg == -1)
        throw BuilderException("Damage was not set in the recordFightBuilder");
    if(recordAttack.enemy_hp == -1)
        throw BuilderException("Enemy HP was not set in the recordFightBuilder");
    return recordAttack;
}

RecordAttackBuilder::RecordAttackBuilder(): recordAttack("", "", -1, -1) {
}
