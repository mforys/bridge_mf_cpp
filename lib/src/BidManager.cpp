//
//  BidManager.cpp
//  bridge_mf
//
//  Created by forysm on 10/28/18.
//

#include "BidManager.h"

//#include <iostream>
#include <string>

void BidManager::addBid(Bid bid)
{
    bids.push_back(bid);
}

Error BidManager::bid(BidVolume volume, Suit suit)
{
    Bid bid = Bid(volume, suit);
    Bid* previousNonPassBid = getPreviousRegularBid();
    if (previousNonPassBid && volume < previousNonPassBid->volume)
    {
        return CANT_ADD_BID;
    }

    if (previousNonPassBid && volume == previousNonPassBid->volume)
    {
        if (suit <= previousNonPassBid->suit)
        {
            return CANT_ADD_BID;
        }
    }

    addBid(bid);
    return SUCCESS;
}

void BidManager::pass()
{
    Bid bid = Bid(PASS, CLUB);
    addBid(bid);
}

Error BidManager::contra()
{
    Bid bid = Bid(CONTRA, CLUB);
    addBid(bid);
    return SUCCESS;
}

Error BidManager::recontra()
{
    Bid bid = Bid(RECONTRA, CLUB);
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

Bid* BidManager::getPreviousRegularBid()
{
    auto iter = bids.rbegin();
    while (++iter != bids.rend())
    {
        if (iter->volume > PASS)
            return &*iter;
    };

    return nullptr;
}

std::string BidManager::getAllBids_s()
{
    std::string output;

    for (const auto& bid : bids)
    {
        switch (bid.volume)
        {
            case RECONTRA:
                output.append("RECONTRA");
                break;
            case CONTRA:
                output.append("CONTRA");
                break;
            case PASS:
                output.append("PASS");
                break;
            default:
                output.append(std::to_string(bid.volume));
                output.append(" " + suit_s(bid.suit));
        }

        output.append(" \n");
    }

    return output;
}
