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

Card::Card(Suit suit, Rank rank)
{
    //ctor
    v = suit * CARD_HAND_COUNT + rank;
    s = suit;
    r = rank;
}

Card::~Card()
{
    //dtor
}

Card::Card(const Card& other)
{
    //copy ctor
    //cout <<" Konstruktor kopiujacy" <<endl;

    v = other.v;
    r = other.r;
    s = other.s;
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

    v = rhs.v;
    r = rhs.r;
    s = rhs.s;

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

bool Card::operator<(const Card& rhs) const
{
    return this->value() < rhs.value();
}

bool Card::operator>(const Card& rhs) const
{
    return this->value() > rhs.value();
}
