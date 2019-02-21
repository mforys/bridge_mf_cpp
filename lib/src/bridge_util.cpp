#include "bridge_util.h"

#include <string>
#include <cstdlib>
#include <ctime>

static bool firstTime = true;

UI getRandom()
{
    if (firstTime)
    {
        srand(time(NULL));
        firstTime = false;
    }

    UI r = rand() % CARD_COUNT;

    return r;
}

UI getRandom(UI low, UI up)
{
    if (firstTime)
    {
        srand(time(NULL));
        firstTime = false;
    }

    UI r = rand() % (up - low) + low;
    return r;
}

UI getRandom(UI i)
{
    if (firstTime)
    {
        srand(time(NULL));
        firstTime = false;
    }

    UI r = rand() % i;
    return r;
}

std::string suit_s(Suit suit)
{
    std::string s;

    switch (suit)
    {
        case CLUB:
            s.append("C");
            break;
        case DIAMOND:
            s.append("D");
            break;
        case HEART:
            s.append("H");
            break;
        case SPADE:
            s.append("S");
            break;
        default:
            s.append("NT");
    }

    return s;
}

std::string seat_s(Seat seat)
{
    std::string s;

    switch (seat)
    {
        case SOUTH:
            s.append("S");
            break;
        case WEST:
            s.append("W");
            break;
        case NORTH:
            s.append("N");
            break;
        case EAST:
            s.append("E");
            break;
    }

    return s;
}
