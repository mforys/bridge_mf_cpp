#ifndef DEAL_H
#define DEAL_H

#include "bridge_util.h"
#include "Hand.h"

class Deal
{
  UI m_Cards[CARDS_COUNT];
  Hand m_Hands[HANDS_COUNT];

    public:
        Deal();
        virtual ~Deal();
        UI * get_cards();
        Hand * get_hand(UI i);

    protected:
    private:

        void swap(UI i, UI j);
};

#endif // DEAL_H
