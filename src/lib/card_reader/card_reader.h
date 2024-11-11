#ifndef CARD_READER_H
#define CARD_READER_H

#include <string_view>
#include <vector>

namespace mtg_card {
struct Card;
}

namespace card_reader {

class CardReader
{
public:
    auto readCards(std::string_view path) -> std::vector<mtg_card::Card>;
};

}

#endif //CARD_READER_H
