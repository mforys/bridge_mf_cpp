#ifndef BRIDGE_UTIL_H_INCLUDED
#define BRIDGE_UTIL_H_INCLUDED

#define CARD_COUNT      52
#define CARD_HAND_COUNT 13
#define HAND_COUNT       4
#define SUIT_COUNT       4

typedef unsigned int    UI;
typedef unsigned char byte;

enum Seat{
    SOUTH,
    WEST,
    NORTH,
    EAST
};

enum Suit{
    CLUB,
    DIAMOND,
    HEART,
    SPADE
};

enum Rank{
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

UI getRandomCard();
UI getRandom(UI i);

#endif // BRIDGE_UTIL_H_INCLUDED
