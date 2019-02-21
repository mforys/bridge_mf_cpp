#include "gtest/gtest.h"
#include "Card.h"

TEST (CardTest, Basic)
{
    Card card(CLUB, TWO);

    EXPECT_EQ (card.suit(), CLUB);
    EXPECT_EQ (card.rank(), TWO);
}

TEST (CardTest, Card_constructor_Suit)
{
    Card card0, card1, card2, card3;

    for (int i = 0; i < 10; ++i)
    {
        card0 = Card(CLUB);
        EXPECT_EQ (card0.suit(), CLUB);
        card1 = Card(DIAMOND);
        EXPECT_EQ (card1.suit(), DIAMOND);
        card2 = Card(HEART);
        EXPECT_EQ (card2.suit(), HEART);
        card3 = Card(SPADE);
        EXPECT_EQ (card3.suit(), SPADE);
    }
}

TEST (CardTest, set) {
    Card card(0);

    EXPECT_EQ (card.suit(), CLUB);
    EXPECT_EQ (card.rank(), TWO);

    card.set(1);
    EXPECT_EQ (card.suit(), CLUB);
    EXPECT_EQ (card.rank(), THREE);

    card.set(14);
    EXPECT_EQ (card.suit(), DIAMOND);
    EXPECT_EQ (card.rank(), THREE);
}
