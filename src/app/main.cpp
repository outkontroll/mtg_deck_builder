#include <iostream>
#include "card.h"
#include "card_reader.h"

using namespace std;
using namespace card_reader;

int main(int argc, char** argv)
{
    if(argc < 2)
        return -1;

    CardReader cardReader;
    const auto cards = cardReader.readCards(argv[1]);

    std::cout << cards[0].name;
    if(cards[0].manaCost)
        std::cout << "\nMana: " << *cards[0].manaCost;
    std::cout << "\nColors: ";
    for(const auto& color : cards[0].colors)
        std::cout << color << ", ";
    std::cout << "\n";

    return 0;
}
