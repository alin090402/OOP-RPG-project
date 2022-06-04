//
// Created by ALIN on 04.03.2022.
//

#ifndef RPG_GAME_H
#define RPG_GAME_H


#include "Player.h"
#include "History.h"
#include "RecordAttack.h"
#include "RecordFight.h"

class Game {
public:

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    void Init(const std::string& dirr_name);
    void MainMenu();
    static Game& getGame();
    ~Game();

    void addAttackRecord(const RecordAttack& recordAttack);

    void addFightRecord(const RecordFight& fight);

private:
    Game();

    History<RecordAttack> attack_history;
    History<RecordFight> fight_history;

    std::shared_ptr<Player> player;
    void Fight(const std::shared_ptr<Entity>& monster);
    void FightMenu();

    void ShopMenu();
/*
    void Save();

    void Load();
*/
    void Craft();

    void Sell();

    void ShowHistory();
};

#endif //RPG_GAME_H
