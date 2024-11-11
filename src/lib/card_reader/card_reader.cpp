#include "card_reader.h"
#include "cardFromJson.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

using namespace card_reader;
using json = nlohmann::json;

auto CardReader::readCards(std::string_view path) const -> std::vector<mtg_card::Card>
{
    std::filesystem::path p(path);
    std::ifstream jsonFile{p};
    if(!jsonFile.is_open())
        return {};

    json j;
    jsonFile >> j;

    std::vector<mtg_card::Card> cards;
    cards.reserve(j.size());

    std::transform(j.begin(), j.end(), std::back_inserter(cards), [](const json& card){
        return card.get<mtg_card::Card>();
    });

    return cards;
}
