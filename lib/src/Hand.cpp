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

byte Hand::get_points()
{
	byte points = 0;

	for (byte i = 0; i < CARDS_HAND_COUNT; ++i)
	{
		switch(m_Cards[i].rank())
		{
			case ACE:
				points += 4;
				break;
			case KING:
				points += 3;
				break;
			case QUEEN:
				points += 2;
				break;
			case JACK:
				points += 1;
				break;
		}
	}

	return points;
}

byte Hand::get_suit_card_count(Suit s)
{
	byte count = 0;

	for (byte i = 0; i < CARDS_HAND_COUNT; ++i)
	{
		if (m_Cards[i].suit() == s)
			count++;
	}

	return count;
}
Hand& Hand::operator=(const Hand& other)
{
return *this;
}

bool Hand::operator==(const Hand& other) const
{
///TODO: return ...;
}

