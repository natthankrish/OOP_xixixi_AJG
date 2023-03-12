#ifndef ABILITYCARDSBANK_HPP
#define ABILITYCARDSBANK_HPP
#include "InventoryHolder.hpp"
#include "../Card/AbilityCard.hpp"
#include <vector>

class AbilityCardsBank {
    private: 
        vector<Card> element;
    public: 
        AbilityCardsBank();
        vector<Card> getElement(); 
        Card getElementAt(int);
        virtual void operator+(const Card&);
        virtual void operator-(const Card&);
};

#endif