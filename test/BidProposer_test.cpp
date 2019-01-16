#include "gtest/gtest.h"
#include "BidProposer.h"

TEST (BidProposerTest, entryBid)
{
    BidManager bidManager;
    Deal deal;

    auto proposer = BidProposer(bidManager, deal);

    EXPECT_EQ (Bid(PASS), proposer.entryBid());
}
