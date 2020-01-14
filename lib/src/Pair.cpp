//
//  Pair.cpp
//  Bridge_MF_Demo
//
//  Created by Marek Forys on 08/09/2019.
//

#include "Pair.h"
#include "HandSuitsPoints.h"

Pair::Pair()
{
    hands[0] = Hand();
    hands[1] = Hand();
}

Pair::Pair(Hand hand)
{
    hands[0] = hand;
    hands[1] = Hand();
}

Pair::Pair(UI clubs, UI diamonds, UI hearts, UI spades, UI points)
{
    hands[0] = HandSuitsPoints(clubs, diamonds, hearts, spades, points);
    hands[1] = Hand();
}

Pair::Pair(UI clubs1, UI diamonds1, UI hearts1, UI spades1, UI points1, UI clubs2, UI diamonds2, UI hearts2, UI spades2, UI points2)
{
    hands[0] = HandSuitsPoints(clubs1, diamonds1, hearts1, spades1, points1);
    hands[1] = HandSuitsPoints(clubs2, diamonds2, hearts2, spades2, points2);
}
