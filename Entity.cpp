//
// Created by ALIN on 26.02.2022.
//

#include "Entity.h"
#include "Equipment.h"
#include "Weapon.h"
#include "Utility.h"
#include <utility>

Entity::Entity(std::string name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon)
        : name(std::move(name)), base_stats(baseStats), currentHP(baseStats.getHp()), currentMP(baseStats.getMana()),
        chestplate(chestplate), boots(boots), ring(ring), helmet(helmet), weapon(weapon) {}

void Entity::Attack(Entity *enemy, Attack_type attackType) {
    std::pair<int, float> damage;
    auto *pWeapon = dynamic_cast<Weapon *>( Item::getItemList()[this->weapon]);
    if(pWeapon != nullptr)
    {
        switch (attackType)
        {
            case Attack_type::Light_Attack:
                damage =  pWeapon->LightAttack( *this);
                break;
            case Attack_type::Medium_Attack:
                damage =  pWeapon->MediumAttack( *this);
                break;
            case Attack_type::Heavy_Attack:
                damage =  pWeapon->HeavyAttack( *this);
                break;
            case Attack_type::Special_Attack:
                damage =  pWeapon->SpecialAttack( *this);
                break;
        }
        if(Utility::Random() < damage.second)
        {
            enemy->currentHP -= damage.first;
        }
        std:: cout << name << " " << damage.first << " " << damage.second << std::endl;
    }
    else {
        std::cout << "No weapon equipped" << std::endl;
    }

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

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "name: " << entity.name << "\nbase_stats: " << entity.base_stats << "\ncurrentHP: " << entity.currentHP
       << "\nchestplate: " << entity.chestplate << "\nboots: " << entity.boots << "\nring: " << entity.ring << "\nhelmet: "
       << entity.helmet << "\nweapon: " << entity.weapon;
    return os;
}

const std::string &Entity::getName() const {
    return name;
}

int Entity::getCurrentHp() const {
    return currentHP;
}

int Entity::getWeapon() const {
    return weapon;
}

void Entity::Heal() {
    currentHP = base_stats.getHp();
    currentMP = base_stats.getMana();
}

int Entity::getCurrentMp() const {
    return currentMP;
}

void Entity::UseMana(int mana) {
    currentMP -= mana;
}

Entity::Entity() = default;

