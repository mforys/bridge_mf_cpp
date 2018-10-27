#include "bridge_util.h"
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
