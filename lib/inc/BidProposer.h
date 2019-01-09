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
    Bid proposeBid(Seat hand);

private:

    Bid openingBid();
    Bid responseBid();
    Bid entryBid();
    Bid firstResponse();
    Bid nextResponse();
    bool isPremiumGamePossible();

    BidManager& bidManager;
    Deal& deal;
    Hand currentHand;
    UI points;
    Suit longestSuit;
    Bid previousRegularBid;
    Bid lastPartnerBid;
    GamePattern handStyle;
};

#endif /* BidProposer_h */
