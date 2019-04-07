#ifndef CARD_READER_H
#define CARD_READER_H

#include <string_view>

namespace card_reader {

class CardReader
{
public:
    void readCards(std::string_view path);
};

}

#endif //CARD_READER_H
