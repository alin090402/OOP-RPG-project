//
// Created by ALIN on 14.04.2022.
//

#ifndef RPG_STATS_H
#define RPG_STATS_H


#include <string>
#include <ostream>

class Stats {
public:
    Stats(int hp, int mana, int atk, int def, int dex);
    Stats();

    //friend std::ostream &operator<<(std::ostream &os, const Stats &stats);
    friend Stats operator+(const Stats &a, const Stats &b);
    friend std::ostream &operator<<(std::ostream &os, const Stats &stats);

    [[nodiscard]] int getHp() const;

    [[nodiscard]] int getMana() const;

    [[nodiscard]] int getAtk() const;

    [[nodiscard]] int getDef() const;

    [[nodiscard]] int getDex() const;

private:
    int hp;
    int mana;
    int atk;
    int def;
    int dex;
};


#endif //RPG_STATS_H
