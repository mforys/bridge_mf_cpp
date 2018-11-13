#include "Hand.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

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

Hand::Hand(std::vector<Card>& aCards)
{
    for (int i = 0; i < CARD_HAND_COUNT; ++i)
    {
        cards[i] = aCards[i];
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

    std::sort(cards.begin(), cards.end(), std::greater<Card>());
}

const HandCards& Hand::getCards()
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

std::string Hand::print()
{
    std::string output;
    for (int s = SPADE; s >= CLUB; --s)
    {
        switch(s)
        {
            case SPADE:
                output.append("S: ");
                break;
            case HEART:
                output.append("H: ");
                break;
            case DIAMOND:
                output.append("D: ");
                break;
            case CLUB:
                output.append("C: ");
                break;
        }

        for (byte i=0; i < CARD_HAND_COUNT; ++i)
        {
            auto c = cards[i];
            if (c.suit() == s)
                output.append(c.rank_s());
        }

        output.append("\n");
    }

    return output;
}
