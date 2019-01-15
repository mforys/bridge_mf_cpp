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
        // TODO: cue-bid logic
        return Bid(PASS);
    }
    
    auto bestSuit = bestSuitToPlay();

    switch (bestSuit)
    {
        case NO_TRUMP:
            return Bid(THREE_B, NO_TRUMP);
        case CLUB:
        case DIAMOND:
            return Bid(FIVE_B, bestSuit);
        case HEART:
        case SPADE:
            return Bid(FOUR_B, bestSuit);
        default:
            assert(false);
    }
}

bool BidProposer::isPremiumGamePossible()
{
    UI partnerPointsLimitUp = 0;
    UI partnerPointsLimitDown = 0;
    
    if (isFirstPartnerBidOpening())
    {
        partnerPointsLimitUp = 21;
        partnerPointsLimitDown = 12;
    }
    else if (isPartnerResponsePositive())
    {
        partnerPointsLimitUp = 11;
        partnerPointsLimitDown = 7;
    }
    else
    {
        partnerPointsLimitUp = 6;
        partnerPointsLimitDown = 0;
    }
    
    //auto totalOurPointsLimitUp = partnerPointsLimitUp + points;
    auto totalOurPointsLimitDown = partnerPointsLimitDown + points;
    
    if (totalOurPointsLimitDown > 24)
        return true;

    return false;
}

bool BidProposer::isFirstPartnerBidOpening()
{
    auto partnerSeat = bidManager.getPartnerSeatOfCurrentSeat();
    auto firstPartnerBid = bidManager.getFirstBid(partnerSeat);
    auto myFirstBid = bidManager.getFirstBidOfCurrentSeat();
    
    if (firstPartnerBid < myFirstBid)
        return true;

    return false;
}

bool BidProposer::isPartnerResponsePositive()
{
    auto partnerSeat = bidManager.getPartnerSeatOfCurrentSeat();
    auto firstPartnerBid = bidManager.getFirstBid(partnerSeat);
    auto myFirstBid = bidManager.getFirstBidOfCurrentSeat();
    
    if (firstPartnerBid < myFirstBid)
        assert(false);
    
    if (firstPartnerBid == Bid(PASS) &&
        bidManager.getSecondBid(partnerSeat) == Bid(PASS))
    {
            return false;
    }
    
    return true;
}

Suit BidProposer::bestSuitToPlay()
{
    auto gamePattern =  currentHand.getGamePattern();

    if (gamePattern == SUIT_GAME ||
        gamePattern == TWO_SUIT_GAME)
    {
        return currentHand.getLongestSuit();
    }

    return NO_TRUMP;
}
