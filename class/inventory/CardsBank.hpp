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
};

#endif