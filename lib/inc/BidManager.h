//
//  BidManager.h
//  bridge_mf
//
//  Created by forysm on 10/28/18.
//

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
    BidManager(Seat startSeat);

    void addBid(Bid bid);
    Error bid(BidVolume volume, Suit suit);
    void pass();
    Error contra();
    Error recontra();
    Bid getBid(byte id);
    Bid getLastBid();
    std::string printAllBids();

private:
    Bid* getPreviousRegularBid();
};

#endif /* BidManager_h */
