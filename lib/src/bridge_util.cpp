#include "bridge_util.h"
#include <string>
#include <cstdlib>
#include <ctime>

UI getRandomCard()
{
    srand(time(NULL));
    UI r = rand() % CARD_COUNT;
    return r;
}

UI getRandom(UI i)
{
    srand(time(NULL));
    UI r = rand() % i;
    return r;
}

std::string suit_s(enum Suit suit)
{
    std::string s;

    switch (suit)
    {
        case CLUB:
            s.append("CLUB");
            break;
        case DIAMOND:
            s.append("DIAMOND");
            break;
        case HEART:
            s.append("HEART");
            break;
        case SPADE:
            s.append("SPADE");
            break;
    }

    return s;
}
