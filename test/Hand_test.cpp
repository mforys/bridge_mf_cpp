#include "gtest/gtest.h"
#include "Hand.h"

HandCards createFullClubHand()
{
    HandCards cards;

    for (int i = 0; i < 13; ++i)
    {
        cards[i] = Card(i);
    }

    return cards;
}

HandCards createFullDiamondHand()
{
    HandCards cards;

    for (int i = 0; i < 13; ++i)
    {
        cards[i] = Card(i + 13);
    }

    return cards;
}

HandCards createHand(UI clubs, UI diamonds, UI hearts, UI spades)
{
    HandCards cards;

    for (int i = 0; i < 13; ++i)
    {
        if (i < clubs)
            cards[i] = Card(i + 7);
        else if (i < clubs + diamonds)
            cards[i] = Card(i + CARD_HAND_COUNT);
        else if (i < clubs + diamonds + hearts)
            cards[i] = Card(i + 2 * CARD_HAND_COUNT);
        else
            cards[i] = Card(i + 3 * CARD_HAND_COUNT);
    }

    return cards;
}

TEST (HandTest, Basic) {

    HandCards cards = createFullClubHand();

    Hand hand(cards);

    auto receivedCards = hand.getCards();

    EXPECT_EQ(cards, receivedCards);

    cards = createFullDiamondHand();

    Hand hand2(cards);

    receivedCards = hand2.getCards();

    EXPECT_EQ(cards, receivedCards);
}

TEST (HandTest, getPoints) {

    HandCards cards = createFullClubHand();

    Hand hand(cards);

    auto points = hand.getPoints();

    EXPECT_EQ(points, 10);
}

TEST (HandTest, getLongestSuit) {

    HandCards cards = createFullClubHand();

    Hand hand(cards);

    auto longestSuit = hand.getLongestSuit();

    EXPECT_EQ(longestSuit, CLUB);

    cards = createFullDiamondHand();
    Hand hand2(cards);
    longestSuit = hand2.getLongestSuit();
    EXPECT_EQ(longestSuit, DIAMOND);

    cards = createHand(5, 3, 2, 3);
    Hand h3(cards);
    longestSuit = h3.getLongestSuit();
    EXPECT_EQ(longestSuit, CLUB);

    cards = createHand(3, 5, 2, 3);
    Hand h4(cards);
    longestSuit = h4.getLongestSuit();
    EXPECT_EQ(longestSuit, DIAMOND);

    cards = createHand(3, 1, 6, 3);
    Hand h5(cards);
    longestSuit = h5.getLongestSuit();
    EXPECT_EQ(longestSuit, HEART);

    cards = createHand(3, 2, 3, 5);
    Hand h6(cards);
    //std::cout << h3.print();
    longestSuit = h6.getLongestSuit();
    EXPECT_EQ(longestSuit, SPADE);
}
