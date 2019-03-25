#ifndef HAND_H
#define HAND_H

#include "bridge_util.h"
#include "Card.h"
#include <array>
#include <set>

//#define ARRAY_IMPL

#ifdef ARRAY_IMPL
typedef std::array<Card, CARD_HAND_COUNT> HandCards;
#else
typedef std::set<Card> HandCards;
#endif

class Hand
{
protected:
    HandCards cards;

public:
    Hand();
    Hand(UI cards[]);
    Hand(HandCards& cards);
    Hand(std::vector<Card>& cards);
    Hand(const Hand& other);
    virtual ~Hand();

    void set(Card *first_card_in_hand);
    const HandCards& getCards();
    UI getPoints() const;
    Suit getLongestSuit() const;
    Suit getSecondLongestSuit() const;
    UI getSuitCount(Suit s) const;
    bool isFitInSuit(Suit s) const;
    bool isRenonse() const;
    GamePattern getGamePattern() const;
    char getSeat(byte s);
    std::string print();
    bool insert(Card card);

    virtual Hand& operator=(const Hand& other);
    virtual bool operator==(const Hand& other) const;

private:
    byte firstFreeSlot;

};

#endif // HAND_H
