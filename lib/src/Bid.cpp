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
