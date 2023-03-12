#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "InventoryHolder.hpp"
#include "InventoryException.hpp"
#include "NumberCard.hpp"

class TableCard : public InventoryHolder {
    private :
        vector<NumberCard> contents;
        const int CAPACITY = 5;

    public :
        vector <NumberCard> getCard();
        void operator+(const NumberCard&);
        void operator-(const NumberCard&);
};

#endif