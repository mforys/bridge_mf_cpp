#include "BidEngine.h"

BidEngine::BidEngine(const Deal& deal)
: deal(deal), bidManager(SOUTH)
{
}

Bid BidEngine::proposeBid()
{
    return Bid(ONE_B,CLUB);
}
