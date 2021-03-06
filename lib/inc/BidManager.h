#ifndef BidManager_h
#define BidManager_h

#include "Bid.h"

#include <stdio.h>
#include <vector>

class BidManager
{
    std::vector<Bid> bids;
    Seat startSeat;

public:
    BidManager(Seat startSeat = SOUTH);

    Error addBid(Bid bid);
    bool isPassRoundCompleted();
    Error bid(BidVolume volume, Suit suit);
    void pass();
    Error contra();
    Error recontra();
    Bid getBid(byte id);
    Bid getLastBid();
    Bid getLastPartnerBid();
    Bid getMyLastBid();
    Bid getPreviousRegularBid();
    Bid getFirstBid(Seat s);
    Bid getSecondBid(Seat s);
    Bid getFirstBidOfCurrentSeat();
    Seat getCurrentSeat();
    Seat getPartnerSeatOfCurrentSeat();
    Bid veryNextBid();
    std::string printAllBids();

private:

};

#endif /* BidManager_h */
