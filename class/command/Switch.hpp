#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_
#include "AbilityCommand.hpp"
#include "../../utils/ListOfThing.hpp"

class Switch : public AbilityCommand {
    public:
        Switch(string, string);             // user defined ctor

        void execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};

#endif