#ifndef Bid_h
#define Bid_h

#include <stdio.h>

#include "bridge_util.h"

class Bid
{
    public:
        Bid();
        Bid(BidVolume volume, Suit suit = NO_TRUMP);

        BidVolume volume() const;
        Suit suit() const;
        bool isInvalid() const;

        bool operator==(const Bid& rhs) const;
        bool operator<(const Bid& rhs) const;
        bool operator>(const Bid& rhs) const;
        Bid  operator++(int);

    private:
        BidVolume v;
        Suit s;
};

#endif /* Bid_h */
