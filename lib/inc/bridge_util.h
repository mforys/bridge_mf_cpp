#ifndef BRIDGE_UTIL_H_INCLUDED
#define BRIDGE_UTIL_H_INCLUDED

#include <string>

const unsigned char CARD_COUNT = 52;
const unsigned char CARD_HAND_COUNT = 13;
const unsigned char CARD_SUIT_COUNT = 13;
const unsigned char HAND_COUNT = 4;
const unsigned char SUIT_COUNT = 4;

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
    SPADE,
    NO_TRUMP
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
    NO_BID = -3,
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

enum GamePattern
{
    NO_PATTERN = 0,
    DEFENCE_GAME,
    SUIT_GAME,
    TWO_SUIT_GAME,
    NO_TRUMP_GAME
};

UI getRandom();
UI getRandom(UI i);
UI getRandom(UI low, UI up);
std::string suit_s(Suit suit);
std::string seat_s(Seat seat);

#endif // BRIDGE_UTIL_H_INCLUDED
