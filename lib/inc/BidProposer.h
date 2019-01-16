//
//  BidProposer.h
//  bridge_mf
//
//  Created by Marek Forys on 29/12/2018.
//

#ifndef BidProposer_h
#define BidProposer_h

#include "Deal.h"
#include "BidManager.h"

class BidProposer
{
public:
    BidProposer(BidManager& aBidManager, Deal& aDeal);
    Bid proposeBid();
    Bid proposeBid(Seat seat);
    Bid entryBid();
    Bid openingBid(Hand& hand);

private:
    Bid responseBid();
    Bid firstResponse();
    Bid nextResponse();
    bool isPremiumGamePossible();
    bool isFirstPartnerBidOpening();
    bool isPartnerResponsePositive();
    Suit bestSuitToPlay();

    BidManager& bidManager;
    Deal& deal;
    Hand currentHand;
    UI points;
    Suit longestSuit;
    Bid previousRegularBid;
    Bid lastPartnerBid;
};

#endif /* BidProposer_h */
