#ifndef BidEngine_h
#define BidEngine_h

#include "BidManager.h"
#include "Deal.h"

class BidEngine
{
    const Deal& deal;
    BidManager bidManager;

public:
    BidEngine(const Deal&);
    Bid proposeBid();
};

#endif // BidEngine_h
