#ifndef DEAL_H
#define DEAL_H

#include "bridge_util.h"
#include "Hand.h"

typedef std::array<Card, CARD_COUNT> DealCards;

class Deal
{
    DealCards cards;
    Hand hands[HAND_COUNT];

    public:
        Deal();
        virtual ~Deal();
        const DealCards& getCards();
        Hand * getHand(UI i);

    protected:
    private:

        void swap(UI i, UI j);
};

#endif // DEAL_H
