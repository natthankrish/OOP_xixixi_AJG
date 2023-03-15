#ifndef __ABILITYCARD_HPP__
#define __ABILITYCARD_HPP__

#include <string>
#include "Card.hpp"

using namespace std;

class AbilityCard : public Card {
    private:
        string abilityName;
    public:
        AbilityCard();
        AbilityCard(string);
        AbilityCard& operator=(const AbilityCard& ac);
        string getAbilityName();
        void setAbilityName(string);
        void useCard();
        bool operator!=(const AbilityCard&);
};

#endif
