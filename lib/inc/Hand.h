#ifndef HAND_H
#define HAND_H

#include "bridge_util.h"
#include "Card.h"
#include <array>

typedef std::array<Card, CARD_HAND_COUNT> HandCards;

class Hand
{
    HandCards cards;

public:
    Hand();
    Hand(UI cards[]);
    Hand(std::vector<Card>& cards);
    Hand(const Hand& other);
    virtual ~Hand();

    void set(UI *first_card_in_hand);
    const HandCards& getCards();
    UI getPoints() const;
    UI getSuitCount(Suit s);
    char getSeat(byte s);
    std::string print();

    virtual Hand& operator=(const Hand& other);
    virtual bool operator==(const Hand& other) const;
};

#endif // HAND_H
