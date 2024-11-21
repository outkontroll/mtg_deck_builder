#include "player.h"

using namespace mtg_game;

Player::Player(std::string_view name_)
    : name(name_)
{
}

std::string_view Player::getName() const
{
    return name;
}
