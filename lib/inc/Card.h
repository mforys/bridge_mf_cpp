#ifndef CARD_H
#define CARD_H

#include "bridge_util.h"

class Card
{
   Suit s;
   Rank r;

    public:
        Card();
        Card(UI i);
        Card(Suit s, Rank r);
        virtual ~Card();
	void set(UI i);
        Suit suit();
        Rank rank();
        const char suit_s();
        const char rank_s();
        Card(const Card& other);
        Card& operator=(const Card& other);
    protected:
    private:
};

#endif // CARD_H
