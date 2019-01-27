#ifndef HAND_H
#define HAND_H

#include "bridge_util.h"
#include "Card.h"
#include <array>

typedef std::array<Card, CARD_HAND_COUNT> HandCards;

class Hand
{
protected:
    HandCards cards;

public:
    Hand();
    //Hand(UI clubs, UI diamonds, UI hearts, UI spades, UI points);
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
    //Card insertCard(Suit suit);

    virtual Hand& operator=(const Hand& other);
    virtual bool operator==(const Hand& other) const;

private:

};

#endif // HAND_H
