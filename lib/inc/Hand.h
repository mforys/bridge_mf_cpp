#ifndef HAND_H
#define HAND_H

#include "bridge_util.h"
#include "Card.h"

class Hand
{
  Card m_Cards[CARD_HAND_COUNT];

public:
  Hand();
  Hand(UI *i);
  Hand(const Hand& other);
  virtual ~Hand();
  void set(UI *first_card_in_hand);
  Card * get_cards();
  UI get_points();
  UI get_suit_card_count(Suit s);
  char get_seat(byte s);
  virtual Hand& operator=(const Hand& other);
  virtual bool operator==(const Hand& other) const;
};

#endif // HAND_H
