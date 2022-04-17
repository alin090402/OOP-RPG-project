//
// Created by ALIN on 26.02.2022.
//

#include "Entity.h"
#include "Equipment.h"
#include <utility>
//#include "Weapon.h"

Entity::Entity(std::string name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon)
        : name(std::move(name)), base_stats(baseStats), currentHP(baseStats.hp),
        chestplate(chestplate), boots(boots), ring(ring), helmet(helmet), weapon(weapon) {}

void Entity::Attack(Entity *enemy, Attack_type attackType) {
    int damage;
    damage = base_stats.atk;
    if(attackType == Attack_type::Light_Attack)
    {
        //damage = dynamic_cast<Weapon *> Item::Items[this->Weapon].LightAttack
    }
    //TODO: implementarea tipurilor de atacuri si a sansei de reusita

    enemy->currentHP -= damage;
}

Stats Entity::stats() const {
    Stats total_stats = base_stats;
    for(auto equipment:equipments())
    {
        try{
            auto* p = dynamic_cast< Equipment* > (Item::getItemList()[equipment]);
            if(p)
                total_stats = total_stats + p->bonus_stats;
                //TODO: adauga alte exceptie pentru cand pe poz respectiva nu este un Equipment
            else throw(-1);
        }
        catch(int) {


        }
    }
    return total_stats;
}

std::vector<int> Entity::equipments() const {
    return std::vector<int>{chestplate, boots, ring, helmet, weapon};
}

[[maybe_unused]] bool Entity::isAlive() const {
    return currentHP > 0;
}
