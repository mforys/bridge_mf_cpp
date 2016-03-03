#include "Card.h"
#include <cstdlib>

#define ASCII_2_CODE 50

Card::Card()
{
    //ctor
    UI i = get_random_card();

    r = (Rank) (i % CARDS_HAND_COUNT);
    s = (Suit) (i / CARDS_HAND_COUNT);
}

Card::Card(UI i)
{
    //ctor
    r = (Rank) (i % CARDS_HAND_COUNT);
    s = (Suit) (i / CARDS_HAND_COUNT);
}

Card::Card(Suit s, Rank r)
{
    //ctor
    this->s = s;
    this->r = r;
}

Card::~Card()
{
    //dtor
}

Card::Card(const Card& other)
{
    //copy ctor
}

Suit Card::suit()
{
    return s;
}

Rank Card::rank()
{
    return r;
}

const char Card::suit_s()
{
    switch(s)
    {
        case CLUB:
            return 'C';
        case DIAMOND:
            return 'D';
        case HEART:
            return 'H';
        default:
        //case SPADE:
            return 'S';
    }
}

const char Card::rank_s()
{
    switch(r)
    {
        case ACE:
            return 'A';
        case KING:
            return 'K';
        case QUEEN:
            return 'Q';
        case JACK:
            return 'J';
        case TEN:
            return 'T';
        default:
            return (r + ASCII_2_CODE);
    }
}

Card& Card::operator=(const Card& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
