#include "gtest/gtest.h"
#include "Card.h"

TEST (CardTest, Basic) {
    Card card(CLUB, TWO);

    EXPECT_EQ (card.suit(), CLUB);
    EXPECT_EQ (card.rank(), TWO);
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
