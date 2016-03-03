#include "Hand.h"

Hand::Hand()
{

}

Hand::Hand(const Hand& other)
{

}

Hand::Hand(UI *first_card_in_hand)
{
    for (UI j = 0; j < CARDS_HAND_COUNT; ++j)
    {
      m_Cards[j].set(*(first_card_in_hand + j));
    }
}

Hand::~Hand()
{

}

void Hand::set(UI *first_card_in_hand)
{
    for (UI j = 0; j < CARDS_HAND_COUNT; ++j)
    {
      m_Cards[j].set(*(first_card_in_hand + j));
    }
}

Card * Hand::get_cards()
{
    return m_Cards;
}

Hand& Hand::operator=(const Hand& other)
{
return *this;
}

bool Hand::operator==(const Hand& other) const
{
///TODO: return ...;
}

