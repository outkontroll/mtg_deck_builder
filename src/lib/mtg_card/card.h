#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include <optional>
#include "types.h"
#include "colors.h"

namespace mtg_card {

struct Card
{
    std::vector<Color> colors;
    std::vector<Type> types;
    std::optional<std::string> manaCost;
    std::string name = "";
    int convertedManaCost = 0;
};

}

#endif // CARD_H
