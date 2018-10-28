//
//  BidManager.cpp
//  bridge_mf
//
//  Created by forysm on 10/28/18.
//

#include "BidManager.h"

void BidManager::addBid(Bid bid)
{
    bids.push_back(bid);
}

Error BidManager::addBid(byte volume, Suit suit)
{
    Bid bid = Bid(volume, suit);
    addBid(bid);
    return SUCCESS;
}

void BidManager::addBid_Pass()
{
    Bid bid = Bid(0, CLUB, true);
    addBid(bid);
}

Error BidManager::addBid_Contra()
{
    Bid bid = Bid(0, CLUB, false, true);
    addBid(bid);
    return SUCCESS;
}

Error BidManager::addBid_Recontra()
{
    Bid bid = Bid(0, CLUB, false, false, true);
    addBid(bid);
    return SUCCESS;
}

Bid BidManager::getBid(byte id)
{
    return bids[id];
}

Bid BidManager::getLastBid()
{
    return bids.back();
}
