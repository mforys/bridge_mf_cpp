#include "Hand.h"

Hand::Hand()
{

}

Hand::Hand(const Hand& other)
{

}

Hand::Hand(UI *first_card_in_hand)
{
    for (UI j = 0; j < CARD_HAND_COUNT; ++j)
    {
      m_Cards[j].set(*(first_card_in_hand + j));
    }
}

Hand::~Hand()
{

}

void Hand::set(UI *first_card_in_hand)
{
    for (UI j = 0; j < CARD_HAND_COUNT; ++j)
    {
      m_Cards[j].set(*(first_card_in_hand + j));
    }
}

Card * Hand::get_cards()
{
    return m_Cards;
}

UI Hand::get_points()
{
	UI points = 0;

	for (byte i = 0; i < CARD_HAND_COUNT; ++i)
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

UI Hand::get_suit_card_count(Suit s)
{
	UI count = 0;

	for (byte i = 0; i < CARD_HAND_COUNT; ++i)
	{
		if (m_Cards[i].suit() == s)
			count++;
	}

	return count;
}

char Hand::get_seat(byte s)
{
	switch (s)
	{
		case WEST:
			return 'W';
		case NORTH:
			return 'N';
		case EAST:
			return 'E';
		default:
			return 'S';
	}
}

Hand& Hand::operator=(const Hand& other)
{
	return *this;
}

bool Hand::operator==(const Hand& other) const
{
	return true;
}

