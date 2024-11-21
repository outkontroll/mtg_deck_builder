#include "game.h"

template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

using namespace mtg_game;

using Phase = std::variant<phases::Untap,
                           phases::Upkeep,
                           phases::Draw,
                           phases::PrecombatMain,
                           phases::Combat,
                           phases::PostcombatMain,
                           phases::EndOfTurn>;

Phase handlePhase(phases::Untap)
{
    return phases::Upkeep{};
}

Phase handlePhase(phases::Upkeep)
{
    return phases::Draw{};
}

Phase handlePhase(phases::Draw)
{
    return phases::PrecombatMain{};
}

Phase handlePhase(phases::PrecombatMain)
{
    return phases::Combat{};
}

Phase handlePhase(phases::Combat)
{
    return phases::PostcombatMain{};
}

Phase handlePhase(phases::PostcombatMain)
{
    return phases::EndOfTurn{};
}

Phase handlePhase(phases::EndOfTurn)
{
    return phases::EndOfTurn{};
}

void Game::updateGame()
{
    using namespace phases;
    turn = std::visit(overloaded{
                                 [](const auto& phase){return handlePhase(phase);}
    }, turn);
}
