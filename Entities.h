//
// Created by ALIN on 26.02.2022.
//

#ifndef RPG_ENTITIES_H
#define RPG_ENTITIES_H


class Entities {
public:
    Entities(int hp, int mana, int atk, int dex, int def);
    Entities();
protected:
    int mana;
    int atk;
    int dex;
    int def;
    int hp;
};


#endif //RPG_ENTITIES_H
