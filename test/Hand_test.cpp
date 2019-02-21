#include "gtest/gtest.h"
#include "Hand.h"
#include "HandSuits.h"

TEST (HandTest, Basic)
{
    Hand hand;

    auto receivedCards = hand.getCards();

    EXPECT_EQ(CARD_HAND_COUNT, receivedCards.size());
}

TEST (HandTest, getPoints) {

    HandSuits hand1(CLUB);
    auto points = hand1.getPoints();
    EXPECT_EQ(points, 10);

    HandSuits hand2(DIAMOND);
    points = hand2.getPoints();
    EXPECT_EQ(points, 10);

    HandSuits hand3(HEART);
    points = hand3.getPoints();
    EXPECT_EQ(points, 10);

    HandSuits hand4(SPADE);
    points = hand4.getPoints();
    EXPECT_EQ(points, 10);
}

TEST (HandTest, getLongestSuit) {

    HandSuits hand(CLUB);

    auto longestSuit = hand.getLongestSuit();

    EXPECT_EQ(longestSuit, CLUB);

    HandSuits hand2(DIAMOND);
    longestSuit = hand2.getLongestSuit();
    EXPECT_EQ(longestSuit, DIAMOND);

    HandSuits h3(5, 3, 2, 3);
    longestSuit = h3.getLongestSuit();
    EXPECT_EQ(longestSuit, CLUB);

    HandSuits h4(3, 5, 2, 3);
    longestSuit = h4.getLongestSuit();
    EXPECT_EQ(longestSuit, DIAMOND);

    HandSuits h5(3, 1, 6, 3);
    longestSuit = h5.getLongestSuit();
    EXPECT_EQ(longestSuit, HEART);

    HandSuits h6(3, 2, 3, 5);
    longestSuit = h6.getLongestSuit();
    EXPECT_EQ(longestSuit, SPADE);
}

TEST (HandTest, insertCard) {
    Hand h;
    HandCards cards;

    Card c = Card(CLUB);

    EXPECT_EQ(true, h.insert(c));
}
