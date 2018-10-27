#ifndef DEAL_H
#define DEAL_H

#include "bridge_util.h"
#include "Hand.h"

class Deal
{
  UI m_Cards[CARD_COUNT];
  Hand m_Hands[HAND_COUNT];

    public:
        Deal();
        virtual ~Deal();
        UI * getCards();
        Hand * getHand(UI i);

    protected:
    private:

        void swap(UI i, UI j);
};

#endif // DEAL_H
