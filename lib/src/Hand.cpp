#include "Hand.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <set>

Hand::Hand()
: firstFreeSlot(0)
{
}

Hand::Hand(const Hand& other)
: firstFreeSlot(0)
{
    cards = other.cards;
}

Hand::Hand(HandCards& aCards)
: cards(aCards), firstFreeSlot(0)
{
}

Hand::Hand(std::vector<Card>& aCards)
: firstFreeSlot(0)
{
    for (int i = 0; i < CARD_HAND_COUNT; ++i)
    {
#ifdef ARRAY_IMPL
        cards[i] = aCards[i];
#else
        cards.insert(aCards[i]);
#endif
    }
}

Hand::~Hand()
{
}

void Hand::set(Card *first_card_in_hand)
{
    for (UI j = 0; j < CARD_HAND_COUNT; ++j)
    {
#ifdef ARRAY_IMPL
        cards[j] = *(first_card_in_hand + j);
#else
        cards.insert(*(first_card_in_hand + j));
#endif
    }

#ifdef ARRAY_IMPL
    std::sort(cards.begin(), cards.end(), std::greater<Card>());
#endif
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
        points += card.points();
    }

    return points;
}

Suit Hand::getLongestSuit() const
{
    Suit longestSuit = NO_TRUMP;
    UI maxCardCount = 0;
    Suit currentSuit = NO_TRUMP;
    UI currentSuitCardCount = 0;

    for (auto s = 0; s < SUIT_COUNT; ++s)
    {
        currentSuit = (Suit)s;
        currentSuitCardCount = getSuitCount(currentSuit);

        if (currentSuitCardCount > maxCardCount)
        {
            maxCardCount = currentSuitCardCount;
            longestSuit = currentSuit;
        }
    }

    return longestSuit;
}

Suit Hand::getSecondLongestSuit() const
{
    Suit longestSuit = getLongestSuit();

    UI maxCardCount = 0;
    Suit secondLongestSuit = NO_TRUMP;
    Suit currentSuit = NO_TRUMP;
    UI currentSuitCardCount = 0;

    for (auto s = 0; s < SUIT_COUNT; ++s)
    {
        currentSuit = (Suit)s;

        if (currentSuit == longestSuit)
        {
            continue;
        }

        currentSuitCardCount = getSuitCount(currentSuit);

        if (currentSuitCardCount > maxCardCount)
        {
            maxCardCount = currentSuitCardCount;
            secondLongestSuit = currentSuit;
        }
    }

    return secondLongestSuit;
}

UI Hand::getSuitCount(Suit s) const
{
    UI count = 0;

    for (const auto & card : cards)
    {
        if (card.suit() == s)
            count++;
    }

    return count;
}

bool Hand::isFitInSuit(Suit s) const
{
    auto cardCountInSuit = getSuitCount(s);
    if (cardCountInSuit > 2)
        return true;
    return false;
}

bool Hand::isRenonse() const
{
    if (getSuitCount(CLUB) &&
        getSuitCount(DIAMOND) &&
        getSuitCount(HEART) &&
        getSuitCount(SPADE))
    {
        return false;
    }

    return true;
}

GamePattern Hand::getGamePattern() const
{
    auto gamePattern = NO_PATTERN;
    auto longestSuit = getLongestSuit();

    if (getSuitCount(longestSuit) > 4)
    {
        gamePattern = SUIT_GAME;
        if (getSecondLongestSuit() > 4)
        {
            gamePattern = TWO_SUIT_GAME;
        }
    }
    else
    {
        if (isRenonse())
        {
            gamePattern = DEFENCE_GAME;
        }
        else
        {
            gamePattern = NO_TRUMP_GAME;
        }
    }

    return gamePattern;
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
        cards = other.cards;
    }

    // by convention, always return *this
    return *this;
}

bool Hand::operator==(const Hand& other) const
{
    if (this == &other)
        return true;

#ifdef ARRAY_IMPL
    for (byte i = 0; i < CARD_HAND_COUNT; ++i)
    {
        if (cards[i] != other.cards[i])
            return false;
    }
#else
    if (cards != other.cards)
        return false;
#endif

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

#ifdef ARRAY_IMPL
        for (byte i=0; i < CARD_HAND_COUNT; ++i)
        {
            auto c = cards[i];
#else
        for (auto c : cards)
        {
#endif
            if (c.suit() == s)
                output.append(c.rank_s());
        }

        output.append("\n");
    }

    return output;
}

bool Hand::insert(Card card)
{
#ifdef ARRAY_IMPL
    for (UI i = 0; i < firstFreeSlot; ++i)
    {
        if (cards[i] == card)
        {
            return false;
        }
    }

    cards[firstFreeSlot] = card;
    ++firstFreeSlot;
    return true;
#else

    auto cardsInHandCount = cards.size();
    assert(cardsInHandCount < CARD_HAND_COUNT);

    if (cardsInHandCount < CARD_HAND_COUNT)
    {
        cards.insert(card);
    	return true;
    }

    return false;
#endif
}
