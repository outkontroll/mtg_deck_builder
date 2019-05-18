#include "card_reader.h"
#include "card.h"
#include "cardFromJson.h"
#include <fstream>
#include <algorithm>

using namespace card_reader;
using json = nlohmann::json;

auto CardReader::readCards(std::string_view path) -> std::vector<mtg_card::Card>
{
    std::ifstream jsonFile{path.data()};
    if(!jsonFile.is_open())
        return {};

    json j;
    jsonFile >> j;

    std::vector<mtg_card::Card> cards;
    cards.reserve(j.size());

    std::transform(j.begin(), j.end(), std::back_inserter(cards), [](const nlohmann::json& card){
        return card.get<mtg_card::Card>();
    });

    return cards;
}
