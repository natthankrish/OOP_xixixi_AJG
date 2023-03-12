#ifndef __ABILITYCARD_HPP__
#define __ABILITYCARD_HPP__

#include <string>
#include "Card.hpp"

using namespace std;

class AbilityCard : Card {
    private:
        string abilityName;
    public:
        AbilityCard(string);
        string getAbilityName();
        void setAbilityName(string);
        void useCard();
};

#endif
