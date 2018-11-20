#ifndef CARD_H
#define CARD_H

#include "bridge_util.h"

class Card
{
        Suit s;
        Rank r;
        byte v;

    public:
        Card();
        Card(UI i);
        Card(Suit s, Rank r);
        Card(const Card& other);
        virtual ~Card();
	    
        void set(UI i);
		byte value() const;
        Suit suit() const;
        Rank rank() const;
        const char suit_s();
        std::string rank_s();

        Card& operator=(const Card& other);
        bool operator==(const Card& rhs) const;
        bool operator!=(const Card& rhs) const;
        bool operator<(const Card& rhs) const;
        bool operator>(const Card& rhs) const;
    protected:
    private:
};

#endif // CARD_H
