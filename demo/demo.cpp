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

    bidManager.pass();
    bidManager.bid(ONE_B, CLUB);
    bidManager.bid(ONE_B, SPADE);
    bidManager.contra();
    bidManager.recontra();
    bidManager.bid(TWO_B, DIAMOND);
    bidManager.bid(TWO_B, HEART);
    bidManager.pass();
    bidManager.bid(FOUR_B, HEART);
    bidManager.pass();
    bidManager.bid(FOUR_B, NO_TRUMP);
    bidManager.contra();
    bidManager.bid(FIVE_B, DIAMOND);
    bidManager.contra();
    bidManager.bid(SIX_B, HEART);
    cout << bidManager.printAllBids() << endl;
    return 0;
}
