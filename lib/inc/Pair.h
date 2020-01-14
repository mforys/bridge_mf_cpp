//
//  Pair.hpp
//  Bridge_MF_Demo
//
//  Created by Marek Forys on 08/09/2019.
//

#ifndef Pair_hpp
#define Pair_hpp

#include "Hand.h"

class Pair
{
public:
    Pair();
    Pair(Hand hand);
    Pair(UI clubs, UI diamonds, UI hearts, UI spades, UI points);
    Pair(UI clubs1, UI diamonds1, UI hearts1, UI spades1, UI points1, UI clubs2, UI diamonds2, UI hearts2, UI spades2, UI points2);

private:
    Hand hands[2];
};

#endif /* Pair_hpp */
