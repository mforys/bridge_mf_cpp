#ifndef HAND_SUITS_H
#define HAND_SUITS_H

#include "Hand.h"

class HandSuits : public Hand
{
public:
    HandSuits(UI clubs, UI diamonds, UI hearts, UI spades);
};

#endif /* HAND_SUITS_H */
