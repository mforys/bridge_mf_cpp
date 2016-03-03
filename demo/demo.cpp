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

/*    for (i=0; i<CARDS_COUNT; ++i)
        cout << "Card["<<i<<"] = "<<get_random_card()<<endl;

    Card *c;

    for (i=0; i<CARDS_COUNT; ++i)
    {
        c = new Card();
        cout << "Card["<<i<<"] = ["<<c->suit_s()<<","<<c->rank_s()<<"]"<<endl;
        delete c;
    }

    c = new Card(SPADE, TEN);
    cout << "Card["<<i<<"] = ["<<c->suit_s()<<","<<c->rank_s()<<"]"<<endl;

    for (i=0; i<CARDS_COUNT; ++i)
    {
        c = new Card(i);
        cout << "Card["<<i<<"] = ["<<c->suit_s()<<","<<c->rank_s()<<"]"<<endl;
    }
*/
    Deal d;
    Card *c = NULL;

    UI *cards = d.get_cards();

//    for (i=0; i<CARD_COUNT; ++i)
//    {
//        c = new Card(cards[i]);
//        cout << "Card["<<i<<"] = "<<cards[i]<<" = ["<<c->suit_s()<<","<<c->rank_s()<<"]"<<endl;
//        delete c;
//    }
//
//    cout << endl <<endl;

    for (byte h=0; h<HAND_COUNT; ++h)
    {

        Hand *hand = d.get_hand(h);

        cout << "Hand " << hand->get_seat(h) << ", Points = " << hand->get_points();
        cout << ", Suits = [" << hand->get_suit_card_count(CLUB)<<","<< hand->get_suit_card_count(DIAMOND)<<",";
        cout << hand->get_suit_card_count(HEART) << "," << hand->get_suit_card_count(SPADE) <<"]";
        cout << endl << "--------" << endl;

        Card *c = hand->get_cards();

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
