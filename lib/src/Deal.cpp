#include "Deal.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void Deal::swap(UI i, UI j)
{
    UI temp = m_Cards[i];
    m_Cards[i] = m_Cards[j];
    m_Cards[j] = temp;
}

Deal::Deal()
{
    cout << "Konstruktor dla Deal" << endl;

    UI j;

    for (UI i = 0; i < CARDS_COUNT; ++i)
        m_Cards[i] = i;

    for (UI i = CARDS_COUNT-1; i > 0; --i)
    {
        j = get_random(i);
        swap(i,j);
    }

    // generate Hands
    for (UI h = 0; h < HANDS_COUNT; ++h)
        m_Hands[h].set(m_Cards + h*CARDS_HAND_COUNT);
}

Deal::~Deal()
{
    //dtor
}

UI * Deal::get_cards()
{
    return m_Cards;
}

Hand * Deal::get_hand(UI i)
{
    return &m_Hands[i];
}
