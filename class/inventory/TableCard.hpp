#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "InventoryHolder.hpp"
#include "InventoryException.hpp"
#include "../Card/NumberCard.hpp"

class TableCard : public InventoryHolder {
    private :
        vector<NumberCard> contents;
        const int CAPACITY = 5;

    public :
        TableCard();
        vector <NumberCard> getCard();
        NumberCard getCardAt(int);
        void operator+(const NumberCard&);
        void operator-(const NumberCard&);
};

#endif