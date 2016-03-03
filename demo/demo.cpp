#include <iostream>
#include <cstdlib>

#include "Card.h"
#include "Deal.h"
#include "bridge_util.h"

using namespace std;

int main()
{
    cout << "BRIDGE MF" << endl <<"---------"<<endl;
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

    for (i=0; i<CARDS_COUNT; ++i)
    {
        c = new Card(cards[i]);
        cout << "Card["<<i<<"] = "<<cards[i]<<" = ["<<c->suit_s()<<","<<c->rank_s()<<"]"<<endl;
        delete c;
    }

    return 0;
}
