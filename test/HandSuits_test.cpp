#include "gtest/gtest.h"
#include "HandSuits.h"

TEST (HandSuits_Test, Basic) {

    HandSuits hand(4,4,4,1);

    EXPECT_EQ(4, hand.getSuitCount(CLUB));
    EXPECT_EQ(4, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(4, hand.getSuitCount(HEART));
    EXPECT_EQ(1, hand.getSuitCount(SPADE));
}

TEST (HandSuits_Test, set_0_6_5_2) {

    HandSuits hand(0,6,5,2);

    EXPECT_EQ(0, hand.getSuitCount(CLUB));
    EXPECT_EQ(6, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(5, hand.getSuitCount(HEART));
    EXPECT_EQ(2, hand.getSuitCount(SPADE));
}

TEST (HandSuits_Test, set_NT) {

    HandSuits hand(3,3,4,3);

    EXPECT_EQ(3, hand.getSuitCount(CLUB));
    EXPECT_EQ(3, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(4, hand.getSuitCount(HEART));
    EXPECT_EQ(3, hand.getSuitCount(SPADE));
}

TEST (HandSuits_Test, set_TwoSuits) {

    HandSuits hand(5,5,1,2);

    EXPECT_EQ(5, hand.getSuitCount(CLUB));
    EXPECT_EQ(5, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(1, hand.getSuitCount(HEART));
    EXPECT_EQ(2, hand.getSuitCount(SPADE));

    HandSuits hand2(1,5,5,2);

    EXPECT_EQ(1, hand2.getSuitCount(CLUB));
    EXPECT_EQ(5, hand2.getSuitCount(DIAMOND));
    EXPECT_EQ(5, hand2.getSuitCount(HEART));
    EXPECT_EQ(2, hand2.getSuitCount(SPADE));

    HandSuits hand3(3,0,5,5);

    EXPECT_EQ(3, hand3.getSuitCount(CLUB));
    EXPECT_EQ(0, hand3.getSuitCount(DIAMOND));
    EXPECT_EQ(5, hand3.getSuitCount(HEART));
    EXPECT_EQ(5, hand3.getSuitCount(SPADE));
}

TEST (HandSuits_Test, LongSuit) {

    HandSuits hand(7,0,3,3);

    EXPECT_EQ(7, hand.getSuitCount(CLUB));
    EXPECT_EQ(0, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(3, hand.getSuitCount(HEART));
    EXPECT_EQ(3, hand.getSuitCount(SPADE));

    HandSuits hand2(1,8,2,2);

    EXPECT_EQ(1, hand2.getSuitCount(CLUB));
    EXPECT_EQ(8, hand2.getSuitCount(DIAMOND));
    EXPECT_EQ(2, hand2.getSuitCount(HEART));
    EXPECT_EQ(2, hand2.getSuitCount(SPADE));

    HandSuits hand3(3,1,7,2);

    EXPECT_EQ(3, hand3.getSuitCount(CLUB));
    EXPECT_EQ(1, hand3.getSuitCount(DIAMOND));
    EXPECT_EQ(7, hand3.getSuitCount(HEART));
    EXPECT_EQ(2, hand3.getSuitCount(SPADE));

    HandSuits hand4(2,1,1,9);

    EXPECT_EQ(2, hand4.getSuitCount(CLUB));
    EXPECT_EQ(1, hand4.getSuitCount(DIAMOND));
    EXPECT_EQ(1, hand4.getSuitCount(HEART));
    EXPECT_EQ(9, hand4.getSuitCount(SPADE));
}

TEST (HandSuits_Test, FullSuit) {

    HandSuits hand(CLUB);

    EXPECT_EQ(CARD_SUIT_COUNT, hand.getSuitCount(CLUB));
    EXPECT_EQ(0, hand.getSuitCount(DIAMOND));
    EXPECT_EQ(0, hand.getSuitCount(HEART));
    EXPECT_EQ(0, hand.getSuitCount(SPADE));

    HandSuits hand2(DIAMOND);

    EXPECT_EQ(0, hand2.getSuitCount(CLUB));
    EXPECT_EQ(CARD_SUIT_COUNT, hand2.getSuitCount(DIAMOND));
    EXPECT_EQ(0, hand2.getSuitCount(HEART));
    EXPECT_EQ(0, hand2.getSuitCount(SPADE));

    HandSuits hand3(HEART);

    EXPECT_EQ(0, hand3.getSuitCount(CLUB));
    EXPECT_EQ(0, hand3.getSuitCount(DIAMOND));
    EXPECT_EQ(CARD_SUIT_COUNT, hand3.getSuitCount(HEART));
    EXPECT_EQ(0, hand3.getSuitCount(SPADE));

    HandSuits hand4(SPADE);

    EXPECT_EQ(0, hand4.getSuitCount(CLUB));
    EXPECT_EQ(0, hand4.getSuitCount(DIAMOND));
    EXPECT_EQ(0, hand4.getSuitCount(HEART));
    EXPECT_EQ(CARD_SUIT_COUNT, hand4.getSuitCount(SPADE));
}
