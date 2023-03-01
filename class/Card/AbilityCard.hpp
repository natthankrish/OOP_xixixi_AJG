#ifndef __ABILITYCARD.HPP__
#define __ABILITYCARD.HPP__

#include <string>
#include "Card.hpp"

using namespace std;

class AbilityCard : Card {
    private:
        string abilityName;
    public:
        string getAbilityName();
        void setAbilityName(string);
        void useCard();
};

#endif
