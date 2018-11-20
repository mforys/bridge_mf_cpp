#include "gtest/gtest.h"
#include "Bid.h"

TEST (BidTest, Basic)
{
    Bid bid(ONE_B, CLUB);

    EXPECT_EQ (bid.volume(), ONE_B);
    EXPECT_EQ (bid.suit(), CLUB);
}

TEST (BidTest, LessThan)
{
    Bid bid1(ONE_B, CLUB);
    Bid bid2(TWO_B, CLUB);

    EXPECT_LT(bid1, bid2);
}

TEST (BidTest, LessThan_same_volume)
{
    Bid bid1(ONE_B, CLUB);
    Bid bid2(ONE_B, DIAMOND);

    EXPECT_LT(bid1, bid2);
}

TEST (BidTest, GreaterThan)
{
    Bid bid1(THREE_B, CLUB);
    Bid bid2(TWO_B, CLUB);

    EXPECT_GT(bid1, bid2);
}

TEST (BidTest, GreaterThan_same_volume)
{
    Bid bid1(THREE_B, HEART);
    Bid bid2(THREE_B, CLUB);

    EXPECT_GT(bid1, bid2);
}
