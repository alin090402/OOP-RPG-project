//
// Created by ALIN on 26.02.2022.
//

#include "Entity.h"
#include "Equipment.h"
#include "Weapon.h"
#include "Utility.h"
#include <utility>
#include "Exception.h"
#include "RecordAttackBuilder.h"
#include "Game.h"

Entity::Entity(std::string name, const Stats &baseStats, int chestplate, int boots, int ring, int helmet, int weapon)
        : name(std::move(name)), base_stats(baseStats), currentHP(baseStats.getHp()), currentMP(baseStats.getMana()),
        chestplate(chestplate), boots(boots), ring(ring), helmet(helmet), weapon(weapon) {}

void Entity::Attack(const std::shared_ptr<Entity>& enemy, Attack_type attackType) {
    std::pair<int, double> damage;
    auto *pWeapon = dynamic_cast<Weapon *>( Item::getItemList()[this->weapon]);
    if(pWeapon != nullptr)
    {
        switch (attackType)
        {
            case Attack_type::Light_Attack:
                damage =  pWeapon->LightAttack( shared_from_this());
                break;
            case Attack_type::Medium_Attack:
                damage =  pWeapon->MediumAttack( shared_from_this());
                break;
            case Attack_type::Heavy_Attack:
                damage =  pWeapon->HeavyAttack( shared_from_this());
                break;
            case Attack_type::Special_Attack:
                damage =  pWeapon->SpecialAttack( shared_from_this());
                break;
        }
        if (Utility::Random() < damage.second)
            enemy->currentHP -= std::max(damage.first - enemy->stats().getDef(), 0);
    }
    else {
        damage = std::make_pair(0, 0.0);
        std::cout << "No weapon equipped" << std::endl;
    }
    enemy->currentHP -= std::max(damage.first - enemy->stats().getDef(), 0);
    RecordAttackBuilder attackBuilder;
    attackBuilder.Name(this->name).Damage(damage.first).EnemyName(enemy->name).EnemyHP(enemy->currentHP);
    Game::getGame().addAttackRecord(attackBuilder.build());
}

Stats Entity::stats() const {
    Stats total_stats = base_stats;
    for(auto equipment:equipments())
    {
        try{
            auto* p = dynamic_cast< Equipment* > (Item::getItemList()[equipment]);
            if(p)
                total_stats = total_stats + p->bonus_stats;
            else throw DataException("Not an equipment");
        }
        catch(DataException& e)
        {
            std::cerr << e.what() << std::endl;
            return base_stats;
        }
    }
    return total_stats;
}

std::vector<int> Entity::equipments() const {
    return std::vector<int>{chestplate, boots, ring, helmet, weapon}; // update when I add new equip
}

[[maybe_unused]] bool Entity::isAlive() const {
    return currentHP > 0;
}

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "name: " << entity.name << "\nbase_stats: " << entity.base_stats << "\ncurrentHP: " << entity.currentHP << "\n";
    entity.ShowEquipment(os);
    return os;
}

void Entity::ShowEquipment(std::ostream &os) const {
    os << "Chestplate: " << Item::getItemList()[Item::getIdToPos(chestplate)]->getName() << std::endl;
    os << "Boots: " << Item::getItemList()[Item::getIdToPos(boots)]->getName() << std::endl;
    os << "Ring: " << Item::getItemList()[Item::getIdToPos(ring)]->getName() << std::endl;
    os << "Helmet: " << Item::getItemList()[Item::getIdToPos(helmet)]->getName() << std::endl;
    os << "Weapon: " << Item::getItemList()[Item::getIdToPos(weapon)]->getName() << std::endl;
}

const std::string &Entity::getName() const {
    return name;
}

int Entity::getCurrentHp() const {
    return currentHP;
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

