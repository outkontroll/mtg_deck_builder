#include "card_reader.h"
#include "nlohmann/json.hpp"

#include <fstream>

using namespace card_reader;
using json = nlohmann::json;

void CardReader::readCards(std::string_view path)
{
    std::ifstream jsonFile{path.data()};
    if(!jsonFile.is_open())
        return;

    json j;
    jsonFile >> j;
}
