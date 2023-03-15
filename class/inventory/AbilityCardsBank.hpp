#ifndef ABILITYCARDSBANK_HPP
#define ABILITYCARDSBANK_HPP
#include "InventoryHolder.hpp"
#include "../Card/AbilityCard.hpp"
#include "Player.hpp"
#include <vector>
#include "../../utils/ListOfThing.hpp"

class AbilityCardsBank {
    private: 
        vector<AbilityCard> element;
    public: 
        AbilityCardsBank();
        vector<AbilityCard> getElement(); 
        AbilityCard getElementAt(int);
        virtual void operator+(const AbilityCard&);
        virtual void operator-(const AbilityCard&);
        void bagiAbility(List<Player>&);
};

#endif