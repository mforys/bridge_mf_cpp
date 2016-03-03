#include "bridge_util.h"
#include <cstdlib>
#include <ctime>

UI get_random_card()
{
    srand(time(NULL));
    UI r = rand() % CARD_COUNT;
    return r;
}

UI get_random(UI i)
{
    srand(time(NULL));
    UI r = rand() % i;
    return r;
}
