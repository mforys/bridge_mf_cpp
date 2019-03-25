#include "gtest/gtest.h"
#include "HandSuitsPoints.h"

TEST (HandSuitsPoints_Test, Basic) {

    HandSuitsPoints hand(4,4,4,1,12);

    EXPECT_EQ(4, hand.getSuitCount(CLUB));
    EXPECT_EQ(4, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(4, hand.getSuitCount(HEART));
    EXPECT_EQ(1, hand.getSuitCount(SPADE));

    EXPECT_EQ(12, hand.getPoints());
}

TEST (HandSuitsPoints_Test, NT_hand) {

    HandSuitsPoints hand(4,3,3,3,16);

    EXPECT_EQ(4, hand.getSuitCount(CLUB));
    EXPECT_EQ(3, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(3, hand.getSuitCount(HEART));
    EXPECT_EQ(3, hand.getSuitCount(SPADE));

    EXPECT_EQ(16, hand.getPoints());
}

TEST (HandSuitsPoints_Test, OneSuit_hand) {

    HandSuitsPoints hand(2,5,3,3,13);

    EXPECT_EQ(2, hand.getSuitCount(CLUB));
    EXPECT_EQ(5, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(3, hand.getSuitCount(HEART));
    EXPECT_EQ(3, hand.getSuitCount(SPADE));

    EXPECT_EQ(13, hand.getPoints());
}

TEST (HandSuitsPoints_Test, WeakTwo_hand) {

    HandSuitsPoints hand(5,5,1,2,8);

    EXPECT_EQ(5, hand.getSuitCount(CLUB));
    EXPECT_EQ(5, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(1, hand.getSuitCount(HEART));
    EXPECT_EQ(2, hand.getSuitCount(SPADE));

    EXPECT_EQ(8, hand.getPoints());
}
