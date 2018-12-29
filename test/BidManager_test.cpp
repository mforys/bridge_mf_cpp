#include "gtest/gtest.h"
#include "BidManager.h"

TEST (BidManagerTest, getLastPartnerBid_noBid)
{
    BidManager manager;
    Bid bid = manager.getLastPartnerBid();

    EXPECT_EQ (bid.volume(), NO_BID);
}

TEST (BidManagerTest, getLastPartnerBid_Pass)
{
    BidManager manager;
    manager.addBid(PASS);
    manager.addBid(PASS);
    Bid bid = manager.getLastPartnerBid();

    EXPECT_EQ (bid.volume(), PASS);
}

TEST (BidManagerTest, getLastPartnerBid_RegularBid)
{
    BidManager manager;
    manager.addBid(Bid(ONE_B,DIAMOND));
    manager.addBid(PASS);
    Bid bid = manager.getLastPartnerBid();

    EXPECT_EQ (bid.volume(), ONE_B);
    EXPECT_EQ (bid.suit(), DIAMOND);
}
