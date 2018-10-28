#ifndef BRIDGE_UTIL_H_INCLUDED
#define BRIDGE_UTIL_H_INCLUDED

#include <string>

#define CARD_COUNT      52
#define CARD_HAND_COUNT 13
#define HAND_COUNT       4
#define SUIT_COUNT       4

typedef unsigned int    UI;
typedef unsigned char byte;

enum Seat
{
    SOUTH,
    WEST,
    NORTH,
    EAST
};

enum Suit
{
    CLUB,
    DIAMOND,
    HEART,
    SPADE
};

enum Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

enum Error
{
    SUCCESS,
    FAIL,
    CANT_ADD_BID,
    WRONG_BID
};

enum BidVolume
{
    CONTRA = -2,
    RECONTRA = -1,
    PASS = 0,
    ONE_B,
    TWO_B,
    THREE_B,
    FOUR_B,
    FIVE_B,
    SIX_B,
    SEVEN_B
};

UI getRandomCard();
UI getRandom(UI i);
std::string suit_s(enum Suit suit);

#endif // BRIDGE_UTIL_H_INCLUDED
