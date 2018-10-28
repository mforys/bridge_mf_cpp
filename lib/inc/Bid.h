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
    byte volume;
    Suit suit;
    bool pass;
    bool contra;
    bool recontra;

public:
    Bid(byte volume, Suit suit, bool pass = false, bool contra = false, bool recontra = false);

private:
    //Bid() noexcept;
};

#endif /* Bid_h */
