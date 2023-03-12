#ifndef ABILITYCARDSBANK_HPP
#define ABILITYCARDSBANK_HPP
#include "InventoryHolder.hpp"
#include "../Card/AbilityCard.hpp"
#include <vector>

class AbilityCardsBank : public InventoryHolder {
    private: 
        vector<AbilityCard> element;
    public: 
        AbilityCardsBank();
        vector<AbilityCard> getElement(); 
        AbilityCard getElementAt(int);
};

#endif