//
// Created by ALIN on 14.04.2022.
//

#ifndef RPG_EQUIPMENT_H
#define RPG_EQUIPMENT_H
#include "Item.h"
#include "Stats.h"
#include "Entity.h"

class Equipment :public Item{
public:
    Equipment(int id, Item_type type, const std::string &name, const Stats &bonusStats, int price, int requiredLevel,
              std::vector<std::pair<int, int>> recipe);

    [[nodiscard]] std::shared_ptr<Item> clone() const override;

    [[nodiscard]] const std::vector<std::pair<int, int>> &getRecipe() const;
    friend Stats Entity::stats() const;

    [[nodiscard]] bool Craftable() const override;

    void ShowRecipe(std::ostream &os) const override;


    int getRequiredLvl() const;

    ~Equipment() override;

protected:
    void Afisare(std::ostream &os)const override;

private:
    Stats bonus_stats;
    int price;
    int requiredLevel;
    std::vector<std::pair<int, int> >recipe; // id, quantity


};


#endif //RPG_EQUIPMENT_H
