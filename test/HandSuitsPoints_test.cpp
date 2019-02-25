#include "gtest/gtest.h"
#include "HandSuitsPoints.h"

TEST (HandSuitsPoints_Test, Basic) {

    HandSuitsPoints hand(4,4,4,1,12);

    EXPECT_EQ(4, hand.getSuitCount(CLUB));
    EXPECT_EQ(4, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(4, hand.getSuitCount(HEART));
    EXPECT_EQ(1, hand.getSuitCount(SPADE));

    //EXPECT_EQ(12, hand.getPoints());
}
