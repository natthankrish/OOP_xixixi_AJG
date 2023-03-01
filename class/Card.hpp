#ifndef __CARD.HPP__
#define __CARD.HPP__

#include "class/inventory/InventoryHolder.hpp"

class Card : InventoryHolder
{
    protected:
        string cardType;
        int value;
    public:
        Card& operator=(const Card&);

        void setCardType(string);
        string getCardType();
        void setValue(int);
        int getValue();
};


#endif