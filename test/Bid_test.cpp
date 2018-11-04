#include "gtest/gtest.h"
#include "Bid.h"

TEST (BidTest, Basic) {
    Bid bid(ONE_B, CLUB);

    EXPECT_EQ (bid.volume(), ONE_B);
    EXPECT_EQ (bid.suit(), CLUB);
}
