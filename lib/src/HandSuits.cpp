#include "HandSuits.h"
#include <cassert>

HandSuits::HandSuits(UI clubs, UI diamonds, UI hearts, UI spades)
{
    Card card;

    assert(clubs + diamonds + hearts + spades == CARD_HAND_COUNT);

#ifdef ARRAY_IMPL
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
#else
    while (cards.size() < CARD_HAND_COUNT)
    {
        while (getSuitCount(CLUB) < clubs)
            insert(Card(CLUB));
        while (getSuitCount(DIAMOND) < diamonds)
            insert(Card(DIAMOND));
        while (getSuitCount(HEART) < hearts)
            insert(Card(HEART));
        while (getSuitCount(SPADE) < spades)
            insert(Card(SPADE));
    }
#endif
}

HandSuits::HandSuits(Suit suit)
{
#ifdef ARRAY_IMPL
    UI firstCardID = suit * CARD_SUIT_COUNT;

    for (int i = 0; i < firstCardID + CARD_HAND_COUNT; ++i)
    {
        cards[i] = Card(firstCardID + i);
    }
#else
    while (getSuitCount(suit) < CARD_SUIT_COUNT)
        insert(Card(suit));
#endif
}
