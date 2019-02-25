#include "HandSuits.h"

HandSuits::HandSuits(UI clubs, UI diamonds, UI hearts, UI spades)
{
    Card card;

    assert(clubs + diamonds + hearts + spades == CARD_HAND_COUNT);

    for (int i = 0; i < CARD_HAND_COUNT; ++i)
    {
        if (i < clubs)
            card = Card(CLUB);
        else if (i < clubs + diamonds)
            card = Card(DIAMOND);
        else if (i < clubs + diamonds + hearts)
            card = Card(HEART);
        else
            card = Card(SPADE);

        if (!insert(card))
        {
            --i;
        }
    }
}

HandSuits::HandSuits(Suit suit)
{
    UI firstCardID = suit * CARD_SUIT_COUNT;

    for (int i = 0; i < firstCardID + CARD_HAND_COUNT; ++i)
    {
#ifdef ARRAY_IMPL
        cards[i] = Card(firstCardID + i);
#else
        cards.insert(Card(firstCardID + i));
#endif
    }
}
