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
    manager.addBid(Bid(ONE_B, DIAMOND));
    manager.addBid(PASS);
    Bid bid = manager.getLastPartnerBid();

    EXPECT_EQ (bid.volume(), ONE_B);
    EXPECT_EQ (bid.suit(), DIAMOND);
}

TEST (BidManagerTest, getFirstBid_default_SOUTH)
{
    BidManager manager;
    manager.addBid(Bid(ONE_B, DIAMOND));
    manager.addBid(PASS);
    manager.addBid(Bid(ONE_B, SPADE));
    manager.addBid(Bid(ONE_B, NO_TRUMP));
    
    EXPECT_EQ (Bid(ONE_B, DIAMOND),     manager.getFirstBid(SOUTH));
    EXPECT_EQ (Bid(PASS),               manager.getFirstBid(WEST));
    EXPECT_EQ (Bid(ONE_B, SPADE),       manager.getFirstBid(NORTH));
    EXPECT_EQ (Bid(ONE_B, NO_TRUMP),    manager.getFirstBid(EAST));
}

TEST (BidManagerTest, getFirstBid_WEST)
{
    BidManager manager(WEST);
    manager.addBid(Bid(ONE_B, DIAMOND));
    manager.addBid(PASS);
    manager.addBid(Bid(ONE_B, SPADE));
    manager.addBid(Bid(ONE_B, NO_TRUMP));
    
    EXPECT_EQ (Bid(ONE_B, DIAMOND),     manager.getFirstBid(WEST));
    EXPECT_EQ (Bid(PASS),               manager.getFirstBid(NORTH));
    EXPECT_EQ (Bid(ONE_B, SPADE),       manager.getFirstBid(EAST));
    EXPECT_EQ (Bid(ONE_B, NO_TRUMP),    manager.getFirstBid(SOUTH));
}

TEST (BidManagerTest, getFirstBid_NORTH)
{
    BidManager manager(NORTH);
    manager.addBid(Bid(ONE_B, DIAMOND));
    manager.addBid(PASS);
    manager.addBid(Bid(ONE_B, SPADE));
    manager.addBid(Bid(ONE_B, NO_TRUMP));
    
    EXPECT_EQ (Bid(ONE_B, DIAMOND),     manager.getFirstBid(NORTH));
    EXPECT_EQ (Bid(PASS),               manager.getFirstBid(EAST));
    EXPECT_EQ (Bid(ONE_B, SPADE),       manager.getFirstBid(SOUTH));
    EXPECT_EQ (Bid(ONE_B, NO_TRUMP),    manager.getFirstBid(WEST));
}

TEST (BidManagerTest, getFirstBid_EAST)
{
    BidManager manager(EAST);
    manager.addBid(Bid(ONE_B, DIAMOND));
    manager.addBid(PASS);
    manager.addBid(Bid(ONE_B, SPADE));
    manager.addBid(Bid(ONE_B, NO_TRUMP));
    
    EXPECT_EQ (Bid(ONE_B, DIAMOND),     manager.getFirstBid(EAST));
    EXPECT_EQ (Bid(PASS),               manager.getFirstBid(SOUTH));
    EXPECT_EQ (Bid(ONE_B, SPADE),       manager.getFirstBid(WEST));
    EXPECT_EQ (Bid(ONE_B, NO_TRUMP),    manager.getFirstBid(NORTH));
}

TEST (BidManagerTest, getPartnerSeatOfCurrentSeat)
{
    BidManager manager(EAST);
    manager.addBid(Bid(ONE_B, DIAMOND));
    EXPECT_EQ (WEST,     manager.getPartnerSeatOfCurrentSeat());
    manager.addBid(PASS);
    EXPECT_EQ (NORTH,     manager.getPartnerSeatOfCurrentSeat());
    manager.addBid(Bid(ONE_B, SPADE));
    EXPECT_EQ (EAST,     manager.getPartnerSeatOfCurrentSeat());
    manager.addBid(Bid(ONE_B, NO_TRUMP));
    EXPECT_EQ (SOUTH,     manager.getPartnerSeatOfCurrentSeat());
}
