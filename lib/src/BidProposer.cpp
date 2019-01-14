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
{
}

Bid BidProposer::proposeBid()
{
    auto currentSeat = bidManager.getCurrentSeat();
    return proposeBid(currentSeat);
}

Bid BidProposer::proposeBid(Seat seat)
{
    currentHand = deal.getHand(seat);
    points = currentHand.getPoints();
    longestSuit = currentHand.getLongestSuit();
    previousRegularBid = bidManager.getPreviousRegularBid();
    lastPartnerBid = bidManager.getLastPartnerBid();
    handStyle = currentHand.getGamePattern();

    if (previousRegularBid.isInvalid())
    {
        // opening
        return openingBid();

    }
    else if (!lastPartnerBid.isInvalid() && lastPartnerBid.volume() != PASS)
    {
        // response
        return responseBid();
    }
    else if (lastPartnerBid.isInvalid())
    {
        // entry against oponents bidding
        return entryBid();
    }

    return Bid(PASS);
}

Bid BidProposer::openingBid()
{
    if (points < 11)
    {
        return Bid(PASS);
    }

    if (handStyle == SUIT_GAME || handStyle == TWO_SUIT_GAME)
    {
        return Bid(ONE_B, longestSuit);
    }
    else
    {
        if (points > 14)
        {
            return Bid(ONE_B, NO_TRUMP);
        }
        else
        {
            return Bid(ONE_B, CLUB);
        }
    }
}

Bid BidProposer::responseBid()
{
    if (points < 7)
        return Bid(PASS);

    auto myLastBid = bidManager.getMyLastBid();

    if (myLastBid.isInvalid())
    {
        return firstResponse();
    }
    else
    {
        return nextResponse();
    }
}

Bid BidProposer::entryBid()
{
    return Bid(PASS);
}

Bid BidProposer::firstResponse()
{
    // first response
    auto proposalBid = openingBid();
    BidVolume newVolume = lastPartnerBid.volume();
    Suit newSuit = proposalBid.suit();
    auto isFit = currentHand.isFitInSuit(lastPartnerBid.suit());

    if (proposalBid.volume() == PASS)
    {
        if (isFit)
        {
            newVolume = (BidVolume)((UI)newVolume + 1);
            newSuit = lastPartnerBid.suit();
        }
        else
        {
            newVolume = ONE_B;
            newSuit = NO_TRUMP;
        }
    }
    else
    {
        if (newVolume == lastPartnerBid.volume() && proposalBid.suit() <= lastPartnerBid.suit())
        {
            newVolume = (BidVolume)((UI)proposalBid.volume() + 2);
        }
        else
        {
            newVolume = (BidVolume)((UI)proposalBid.volume() + 1);
        }
    }

    return Bid(newVolume, newSuit);
}

Bid BidProposer::nextResponse()
{
    // is premium game possible?
    if (!isPremiumGamePossible())
    {
        return Bid(PASS);
    }
    
    // which suit or no trump?
    return Bid(THREE_B, NO_TRUMP);
}

bool BidProposer::isPremiumGamePossible()
{
    UI partnerPointsLimitUp = 0;
    UI partnerPointsLimitDown = 0;
    
    

    
    return false;
}


