
#include "HandSuits.h"

HandSuits::HandSuits(UI clubs, UI diamonds, UI hearts, UI spades)
{
    for (int i = 0; i < CARD_HAND_COUNT; ++i)
    {
        if (i < clubs)
            cards[i] = Card(CLUB);
        else if (i < clubs + diamonds)
            cards[i] = Card(DIAMOND);
        else if (i < clubs + diamonds + hearts)
            cards[i] = Card(HEART);
        else
            cards[i] = Card(SPADE);
    }
}
