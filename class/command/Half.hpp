#ifndef _HALF_HPP_
#define _HALF_HPP_
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"
#include "../../utils/ListOfThing.hpp"

class Half : public OrdinaryCommand {
    public:
        Half(string, string);           // user defined ctor

        void execute(TableCard&, List<Player>&, int, long long int&, CardsBank&, AbilityCardsBank&, bool&);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};

#endif