#include "gtest/gtest.h"
#include "HandSuits.h"

TEST (HandSuits_Test, Basic) {

    HandSuits hand(4,4,4,1);

    EXPECT_EQ(4, hand.getSuitCount(CLUB));
    EXPECT_EQ(4, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(4, hand.getSuitCount(HEART));
    EXPECT_EQ(1, hand.getSuitCount(SPADE));
}

TEST (HandSuits_Test, Other) {

    HandSuits hand(0,6,5,2);

    EXPECT_EQ(0, hand.getSuitCount(CLUB));
    EXPECT_EQ(6, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(5, hand.getSuitCount(HEART));
    EXPECT_EQ(2, hand.getSuitCount(SPADE));
}
