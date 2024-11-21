#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <string_view>

namespace mtg_game {

class Player
{
public:
    explicit Player(std::string_view name);

    std::string_view getName() const;

private:
    std::string name;
};

}

#endif //PLAYER_H
