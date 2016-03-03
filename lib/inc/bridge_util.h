#ifndef BRIDGE_UTIL_H_INCLUDED
#define BRIDGE_UTIL_H_INCLUDED

#define CARDS_COUNT      52
#define CARDS_HAND_COUNT 13
#define HANDS_COUNT       4

typedef unsigned int UI;

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

UI get_random_card();
UI get_random(UI i);

#endif // BRIDGE_UTIL_H_INCLUDED
