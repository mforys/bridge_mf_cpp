#ifndef HAND_H
#define HAND_H

#include "bridge_util.h"
#include "Card.h"

class Hand
{
  Card cards[CARD_HAND_COUNT];

  void swap(byte i, byte j);
  byte divide(byte i, byte j);
  void quickSort(byte i, byte j);

public:
    Hand();
    Hand(UI *i);
    Hand(std::vector<Card>& cards);
    Hand(const Hand& other);
    virtual ~Hand();

    void set(UI *first_card_in_hand);
    Card * getCards();
    UI getPoints() const;
    UI getSuitCount(Suit s);
    char getSeat(byte s);
    std::string print();

    virtual Hand& operator=(const Hand& other);
    virtual bool operator==(const Hand& other) const;
};

#endif // HAND_H
