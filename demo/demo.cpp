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

        Card *c = hand->getCards();
        printHand(c);
        cout << endl;

        BidManager bidManager;

        bidManager.pass();
        bidManager.addBid(ONE_B, CLUB);
        bidManager.addBid(ONE_B, SPADE);
        bidManager.contra();
        bidManager.recontra();
    }

    return 0;
}

void printHand(Card *c)
{
    for (byte s=0; s<SUIT_COUNT; ++s)
    {
        switch(s)
        {
            case SPADE:
                cout << "S: ";
                break;
            case HEART:
                cout << "H: ";
                break;
            case DIAMOND:
                cout << "D: ";
                break;
            case CLUB:
                cout << "C: ";
                break;
        }

        for (byte i=0; i < CARD_HAND_COUNT; ++i)
        {
            if ((c+i)->suit() == s)
                cout << (c+i)->rank_s();
        }

        cout << endl;
    }
}
