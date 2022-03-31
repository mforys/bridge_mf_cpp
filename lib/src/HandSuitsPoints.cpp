//
//  HandSuitsPoints.cpp
//  Bridge_MF_Demo
//
//  Created by Marek Forys on 22.02.2019.
//

#include "HandSuitsPoints.h"

#include <iterator>
#include <cassert>

HandSuitsPoints::HandSuitsPoints(UI clubs, UI diamonds, UI hearts, UI spades, UI points)
: HandSuits(clubs, diamonds, hearts, spades)
{
    fixHandToPoints(points);
}

void HandSuitsPoints::fixHandToPoints(UI points)
{
    while (getPoints() != points)
    {
        swapRandomCardWithinSuit();
    }
}

void HandSuitsPoints::swapRandomCardWithinSuit()
{
    auto it = cards.begin();
    std::advance(it, getRandom(CARD_HAND_COUNT));
    auto card = *it;
    auto suit = card.suit();
    cards.erase(it);

    while (!insert(Card(suit)));

    assert(cards.size() == CARD_HAND_COUNT);
}
