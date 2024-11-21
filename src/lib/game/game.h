#ifndef GAME_H
#define GAME_H

#include "phases.h"
#include "player.h"
#include <variant>
#include <vector>

namespace mtg_game {

class Game
{
public:
    Game();

    void updateGame();

private:
    std::variant<phases::Untap,
                 phases::Upkeep,
                 phases::Draw,
                 phases::PrecombatMain,
                 phases::Combat,
                 phases::PostcombatMain,
                 phases::EndOfTurn> turn = phases::PrecombatMain{};

    std::vector<Player> players;
    Player* activePlayer = nullptr;
};

}

#endif // GAME_H
