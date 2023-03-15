#ifndef _ABILITYLESS_HPP_
#define _ABILITYLESS_HPP_
#include "AbilityCommand.hpp"
#include "../../utils/ListOfThing.hpp"

class Abilityless : public AbilityCommand {
    public:
        Abilityless(string, string);                // user defined ctor
        void execute(TableCard&, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};

#endif 