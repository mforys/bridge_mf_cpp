#include <iostream>
#include <cstdlib>

#include "Card.h"
#include "Hand.h"
#include "Deal.h"
#include "bridge_util.h"

using namespace std;

int main()
{
    cout << "BRIDGE MF" << endl <<"---------"<<endl<<endl;
    UI i;

    Deal d;

    for (byte h=0; h<HAND_COUNT; ++h)
    {

        Hand *hand = d.getHand(h);

        cout << "Hand " << hand->getSeat(h) << ", Points = " << hand->getPoints();
        cout << ", Suits = [" << hand->getSuitCount(CLUB)<<","<< hand->getSuitCount(DIAMOND)<<",";
        cout << hand->getSuitCount(HEART) << "," << hand->getSuitCount(SPADE) <<"]";
        cout << endl << "--------" << endl;

        Card *c = hand->getCards();

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

			for (i=0; i<CARD_HAND_COUNT; ++i)
			{
				if ((c+i)->suit() == s)
					cout << (c+i)->rank_s();
			}

			cout << endl;
        }

        cout << endl;
    }

    return 0;
}
