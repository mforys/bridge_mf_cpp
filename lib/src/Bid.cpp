//
//  Bid.cpp
//  bridge_mf
//
//  Created by forysm on 10/27/18.
//

#include "Bid.h"

Bid::Bid()
{}

Bid::Bid(BidVolume volume, Suit suit)
: v(volume), s(suit)
{}

BidVolume Bid::volume() const
{
    return v;
}

Suit Bid::suit() const
{
    return s;
}

bool Bid::operator<(const Bid& rhs) const
{
    if (this->volume() == rhs.volume())
    {
        return this->s < rhs.s;
    }

    return this->volume() < rhs.volume();
}

bool Bid::operator>(const Bid& rhs) const
{
    if (this->volume() == rhs.volume())
    {
        return this->s > rhs.s;
    }

    return this->volume() > rhs.volume();
}

Bid Bid::operator++(int)
{
    if (this->volume() == NO_BID)
    {
        return Bid(ONE_B, CLUB);
    }

    Suit suit = CLUB;
    BidVolume volume = this->volume();

    switch (this->suit())
    {
        case CLUB:
            suit = DIAMOND;
            break;
        case DIAMOND:
            suit = HEART;
            break;
        case HEART:
            suit = SPADE;
            break;
        case SPADE:
            suit = NO_TRUMP;
            break;
        case NO_TRUMP:
            suit = CLUB;
            volume = static_cast<BidVolume>((static_cast<int>(this->volume()) + 1));
            break;
        default:
            suit = CLUB;
            volume = CONTRA;
    }

    return Bid(volume,suit);
}
