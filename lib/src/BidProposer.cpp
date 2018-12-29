//
//  BidProposer.cpp
//  bridge_mf
//
//  Created by Marek Forys on 29/12/2018.
//

#include "BidProposer.h"
#include "Hand.h"

BidProposer::BidProposer(BidManager& aBidManager, Deal& aDeal)
: bidManager(aBidManager), deal(aDeal)
{}

Bid BidProposer::proposeBid()
{
    auto currentSeat = bidManager.getCurrentSeat();
    return proposeBid(currentSeat);
}

Bid BidProposer::proposeBid(Seat seat)
{
    auto currentHand = deal.getHand(seat);
    auto points = currentHand.getPoints();

    if (points < 6)
    {
        return Bid(PASS);
    }
    else
    {
        if (points > 10)
        {
            return bidManager.getPreviousRegularBid()++;
        }
        else
        {
            auto lastPartnerBid = bidManager.getLastPartnerBid();
            if (lastPartnerBid.volume() == NO_BID || lastPartnerBid.volume() == PASS)
            {
                return Bid(PASS);
            }
            else
            {
                auto lastVolume = lastPartnerBid.volume();
                if (lastVolume != SEVEN_B)
                {
                    return Bid((BidVolume)((int)lastVolume + 1), lastPartnerBid.suit());
                }
                else
                {
                    return Bid(PASS);
                }
            }
        }
    }
}
