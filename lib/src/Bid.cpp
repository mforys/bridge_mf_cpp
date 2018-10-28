//
//  Bid.cpp
//  bridge_mf
//
//  Created by forysm on 10/27/18.
//

#include "Bid.h"

Bid::Bid() noexcept
{}

Bid::Bid(byte volume, Suit suit, bool pass, bool contra, bool recontra)
: volume(volume), suit(suit), pass(pass), contra(contra),recontra(recontra)
{}


