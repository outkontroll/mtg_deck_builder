#include <iostream>

#include "card_reader.h"

using namespace std;
using namespace card_reader;

int main(int argc, char** argv)
{
    if(argc < 2)
        return -1;

    CardReader c;
    c.readCards(argv[1]);

    return 0;
}
