#ifndef CARD_READER_H
#define CARD_READER_H

#include <string_view>
#include <vector>

#include "card.h"

namespace card_reader {

class CardReader
{
public:
    auto readCards(std::string_view path) const -> std::vector<mtg_card::Card>;
};

}

#endif //CARD_READER_H
