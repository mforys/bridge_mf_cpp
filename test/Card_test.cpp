#include "gtest/gtest.h"
#include "Card.h"

TEST (CardTest, Basic) {
    Card card(CLUB, TWO);

    EXPECT_EQ (card.suit(), CLUB);
    EXPECT_EQ (card.rank(), TWO);
}
