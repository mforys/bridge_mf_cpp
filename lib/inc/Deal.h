#ifndef DEAL_H
#define DEAL_H

#include "bridge_util.h"
#include "Hand.h"

typedef std::array<Card, CARD_COUNT> DealCards;

class Deal
{


    public:
        Deal();
        virtual ~Deal();
        const DealCards& getCards();
        Hand& getHand(UI i);

    private:
        void swap(UI i, UI j);

        DealCards cards;
        Hand hands[HAND_COUNT];
};

#endif // DEAL_H
