#ifndef CARDSBANK_HPP
#define CARDSBANK_HPP
#include "InventoryHolder.hpp"
#include "../Card/NumberCard.hpp"
#include <vector>

class CardsBank : public InventoryHolder {
    private: 
        vector<NumberCard> element;
    public: 
        CardsBank();
        vector<NumberCard> getElement();
        NumberCard getElementAt(int);
        virtual void operator+(const NumberCard&);
        virtual void operator-(const NumberCard&);
        void bagiKartu(List<Player>&);
        void seeCard();
};

#endif