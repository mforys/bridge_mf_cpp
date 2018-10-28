#include "Card.h"
#include <cstdlib>
#include <iostream>

#define ASCII_2_CODE 50

Card::Card()
{
    //ctor
    UI i = getRandomCard();

    v = i;
    r = (Rank) (i % CARD_HAND_COUNT);
    s = (Suit) (i / CARD_HAND_COUNT);
}

Card::Card(UI i)
{
    //ctor
    v = i;
    r = (Rank) (i % CARD_HAND_COUNT);
    s = (Suit) (i / CARD_HAND_COUNT);
}

Card::Card(Suit s, Rank r)
{
    //ctor
    this->v = s * CARD_HAND_COUNT + r;
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
    //cout <<" Konstruktor kopiujacy" <<endl;

    this->v = other.v;
    this->r = other.r;
    this->s = other.s;
}

void Card::set(UI i)
{
    //ctor
    v = i;
    r = (Rank) (i % CARD_HAND_COUNT);
    s = (Suit) (i / CARD_HAND_COUNT);
}

byte Card::value() const
{
    return v;
}

Suit Card::suit() const
{
    return s;
}

Rank Card::rank() const
{
    return r;
}

const char Card::suit_s()
{
    switch (s)
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

std::string Card::rank_s()
{
    //std:string s;

    switch (r)
    {
    case ACE:
        return "A";
    case KING:
        return "K";
    case QUEEN:
        return "Q";
    case JACK:
        return "J";
    case TEN:
        return "T";
    default:
        return std::string(1, char(r + ASCII_2_CODE));
    }
}

Card& Card::operator=(const Card& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment

    this->v = rhs.v;
    this->r = rhs.r;
    this->s = rhs.s;

    return *this;
}

bool Card::operator==(const Card& rhs) const
{
    if (this == &rhs)
        return true;

    if (v == rhs.v)
        return true;
    else
        return false;
}

bool Card::operator!=(const Card& rhs) const
{
    return !(*this == rhs);
}
