#include "Deal.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void Deal::swap(UI i, UI j)
{
    auto temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}

Deal::Deal()
{
    UI j;

    for (UI i = 0; i < CARD_COUNT; ++i)
        cards[i] = i;

    for (UI i = CARD_COUNT-1; i > 0; --i)
    {
        j = getRandom(i);
        swap(i,j);
    }

    // generate Hands
    for (UI h = 0; h < HAND_COUNT; ++h)
        hands[h].set(&cards[h*CARD_HAND_COUNT]);
}

Deal::~Deal()
{
    //dtor
}

const DealCards& Deal::getCards()
{
    return cards;
}

Hand& Deal::getHand(UI i)
{
    return hands[i];
}
