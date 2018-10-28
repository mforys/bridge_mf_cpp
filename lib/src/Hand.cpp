#include "Hand.h"

#include <algorithm>
#include <functional>
#include <iostream>

Hand::Hand()
{
}

Hand::Hand(const Hand& other)
{
    for (int i = 0; i < CARD_HAND_COUNT; ++i)
    {
        cards[i] = other.cards[i];
    }
}

Hand::~Hand()
{}

void Hand::set(UI *first_card_in_hand)
{
    for (UI j = 0; j < CARD_HAND_COUNT; ++j)
    {
        cards[j].set(*(first_card_in_hand + j));
    }

    quickSort(0, CARD_HAND_COUNT - 1);
}

void Hand::swap(byte i, byte j)
{
    Card temp = cards[i];

    cards[i] = cards[j];
    cards[j] = temp;
}

byte Hand::divide(byte i, byte j)
{
    byte div_index = (i + j) / 2;
    Card div = cards[div_index];

    swap(div_index, j);

    byte current_pos = i;

    for (byte k = i; k < j; ++k)
    {
        if (cards[k].value() > div.value())
        {
            swap(k, current_pos);
            current_pos++;
        }
    }

    swap(j, current_pos);

    return current_pos;
}

void Hand::quickSort(byte i, byte j)
{
    if (i < j)
    {
        byte k = divide(i, j);
        if (k > i)
            quickSort(i, k - 1);
        if (k < j - 1)
            quickSort(k + 1, j);
    }
}

Card * Hand::getCards()
{
    return cards;
}

UI Hand::getPoints() const
{
    UI points = 0;

    for (const auto & card : cards)
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

UI Hand::getSuitCount(Suit s)
{
    UI count = 0;

    for (const auto & card : cards)
    {
        if (card.suit() == s)
            count++;
    }

    return count;
}

char Hand::getSeat(byte s)
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
    if (this != &other) // protect against invalid self-assignment
    {
        for (byte i = 0; i < CARD_HAND_COUNT; ++i)
        {
            cards[i] = other.cards[i];
        }
    }

    // by convention, always return *this
    return *this;
}

bool Hand::operator==(const Hand& other) const
{
    if (this == &other)
        return true;

    for (byte i = 0; i < CARD_HAND_COUNT; ++i)
    {
        if (cards[i] != other.cards[i])
            return false;
    }

    return true;
}
