#include "gtest/gtest.h"
#include "Deal.h"

#include <algorithm>

TEST (DealTest, Basic) {
    Deal deal;

    DealCards cards = deal.getCards();

    EXPECT_EQ (cards.size(), CARD_COUNT);

    std::sort(cards.begin(), cards.end());

    EXPECT_EQ(cards[0], Card(CLUB, TWO));
    EXPECT_EQ(cards[CARD_COUNT-1], Card(SPADE, ACE));
}
