#include "Hand.h"
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

Hand::Hand()
{}

Hand::Hand(const Hand& other)
{}

Hand::~Hand()
{}

void Hand::set(UI *first_card_in_hand)
{
    for (UI j = 0; j < CARD_HAND_COUNT; ++j)
    {
        m_Cards[j].set(*(first_card_in_hand + j));
    }

    quick_sort(0, CARD_HAND_COUNT - 1);
}

void Hand::swap(byte i, byte j)
{
    Card temp = m_Cards[i];

    m_Cards[i] = m_Cards[j];
    m_Cards[j] = temp;
}

byte Hand::divide(byte i, byte j)
{
    byte div_index = (i + j) / 2;
    Card div = m_Cards[div_index];

    swap(div_index, j);

    byte current_pos = i;

    for (byte k = i; k < j; ++k)
    {
        if (m_Cards[k].value() > div.value())
        {
            swap(k, current_pos);
            current_pos++;
        }
    }

    swap(j, current_pos);

    return current_pos;
}

void Hand::quick_sort(byte i, byte j)
{
    if (i < j)
    {
        byte k = this->divide(i, j);
        if (k > i)
            this->quick_sort(i, k - 1);
        if (k < j - 1)
            this->quick_sort(k + 1, j);
    }
}

Card * Hand::get_cards()
{
    return m_Cards;
}

UI Hand::get_points() const
{
    UI points = 0;

    for (const auto & card : m_Cards)
    {
        switch (card.rank())
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
        default:
            break;
        }
    }

    return points;
}

UI Hand::get_suit_card_count(Suit s)
{
    UI count = 0;

    for (const auto & card : m_Cards)
    {
        if (card.suit() == s)
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
    if (this == &other)
        return true;
    else
        return false;
}

