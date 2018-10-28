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

public:
    void addBid(Bid bid);
    Error addBid(byte volume, Suit suit);
    void addBid_Pass();
    Error addBid_Contra();
    Error addBid_Recontra();
    Bid getBid(byte id);
    Bid getLastBid();
};

#endif /* BidManager_h */
