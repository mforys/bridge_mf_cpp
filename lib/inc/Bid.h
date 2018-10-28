//
//  Bid.h
//  bridge_mf
//
//  Created by forysm on 10/27/18.
//

#ifndef Bid_h
#define Bid_h

#include <stdio.h>

#include "bridge_util.h"

class Bid
{
    public:
        BidVolume volume;
        Suit suit;

        Bid(BidVolume volume, Suit suit);

    private:
        Bid();
};

#endif /* Bid_h */
