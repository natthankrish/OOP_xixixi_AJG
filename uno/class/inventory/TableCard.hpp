#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "InventoryHolder.hpp"
#include "InventoryException.hpp"
#include "../Card/NumberCard.hpp"

class TableCard : public InventoryHolder {
    private :
        vector<NumberCard> contents;

    public :
        TableCard();
        vector <NumberCard> getCard();
        void operator+(const NumberCard&);
        void operator-(const NumberCard&);
        NumberCard& Top();
};

#endif