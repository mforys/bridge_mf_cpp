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

    for (byte h=0; h<HAND_COUNT; ++h)
    {

        Hand *hand = d.getHand(h);

        cout << "Hand " << hand->getSeat(h) << ", Points = " << hand->getPoints();
        cout << ", Suits = [" << hand->getSuitCount(CLUB)<<","<< hand->getSuitCount(DIAMOND)<<",";
        cout << hand->getSuitCount(HEART) << "," << hand->getSuitCount(SPADE) <<"]";
        cout << endl << "--------" << endl;

        cout << hand->print();
        cout << endl;
    }

    BidManager bidManager;

    bidManager.pass();
    bidManager.addBid(ONE_B, CLUB);
    bidManager.addBid(ONE_B, SPADE);
    bidManager.contra();
    bidManager.recontra();
    bidManager.addBid(TWO_B, DIAMOND);
    bidManager.addBid(TWO_B, HEART);
    bidManager.pass();
    bidManager.pass();
    bidManager.addBid(FOUR_B, HEART);

    cout << bidManager.getAllBids_s() << endl;
    return 0;
}
