#include "BidEngine.h"

BidEngine::BidEngine(const Deal& deal)
: deal(deal), bidManager(SOUTH)
{
}

Bid proposeBid()
{
    return Bid(ONE_B,CLUB);
}
