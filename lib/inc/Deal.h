#ifndef DEAL_H
#define DEAL_H

#include "bridge_util.h"

class Deal
{
    public:
        Deal();
        virtual ~Deal();
        UI * get_cards();

    protected:
    private:
        UI m_Cards[CARDS_COUNT];
        void swap(UI i, UI j);
};

#endif // DEAL_H
