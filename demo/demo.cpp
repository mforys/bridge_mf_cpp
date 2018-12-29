#include <iostream>
#include <cstdlib>

#include "BidManager.h"
#include "Card.h"
#include "Hand.h"
#include "Deal.h"
#include "bridge_util.h"

using namespace std;

void printHand(Card *c);


int main()
{
    cout << "BRIDGE MF" << endl <<"---------"<<endl<<endl;

    Deal d;

    for (byte h = 0; h < HAND_COUNT; ++h)
    {

        Hand *hand = d.getHand(h);

        cout << "Hand " << hand->getSeat(h) << ", Points = " << hand->getPoints();
        cout << ", Suits = [" << hand->getSuitCount(SPADE)<<","<< hand->getSuitCount(HEART)<<",";
        cout << hand->getSuitCount(DIAMOND) << "," << hand->getSuitCount(CLUB) <<"]";
        cout << endl << "--------" << endl;

        cout << hand->print();
        cout << endl;
    }

    BidManager bidManager(SOUTH);

    auto bid = Bid(NO_BID);

    do
    {
        bid = bid++;
        bidManager.addBid(bid);
    }
    while (bid.volume() != SEVEN_B || bid.suit() != NO_TRUMP);

    cout << bidManager.printAllBids() << endl;
    return 0;
}
