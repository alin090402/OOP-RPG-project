//
// Created by ALIN on 16.04.2022.
//

#ifndef RPG_WEAPON_H
#define RPG_WEAPON_H
#include "Equipment.h"


class Weapon: public Equipment{

public:
    Weapon(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
           const std::vector<std::pair<int, int>> &recipe, int minDamage, int maxDamage, int specialManaCost);

protected:
    void Afisare(std::ostream &os) const override;
    int minDamage;
    int maxDamage;
    int specialManaCost;
public:
    virtual std::pair<int,double> LightAttack(std::shared_ptr<Entity> entity) = 0; // returns the damage and the hit change
    virtual std::pair<int,double> MediumAttack(std::shared_ptr<Entity> entity) = 0;
    virtual std::pair<int,double> HeavyAttack(std::shared_ptr<Entity> entity) = 0;
    virtual std::pair<int,double> SpecialAttack(std::shared_ptr<Entity> entity) = 0;

    ~Weapon() override;
};


#endif //RPG_WEAPON_H
