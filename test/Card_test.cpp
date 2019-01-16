#include "gtest/gtest.h"
#include "Card.h"

TEST (CardTest, Basic) {
    Card card(CLUB, TWO);

    EXPECT_EQ (card.suit(), CLUB);
    EXPECT_EQ (card.rank(), TWO);
}

TEST (CardTest, Card_constructor_Suit) {
    for (int i = 0; i < 100; ++i)
    {
        Card card0(CLUB);
        EXPECT_EQ (card0.suit(), CLUB);
        Card card1(DIAMOND);
        EXPECT_EQ (card1.suit(), DIAMOND);
        Card card2(HEART);
        EXPECT_EQ (card2.suit(), HEART);
        Card card3(SPADE);
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
