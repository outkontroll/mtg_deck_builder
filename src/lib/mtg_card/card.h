#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include <optional>

namespace mtg_card {

struct Card
{
    std::string name = "";
    int convertedManaCost = 0;
    std::optional<std::string> manaCost;
    std::vector<std::string> colors; //TODO
};

}

#endif // CARD_H
