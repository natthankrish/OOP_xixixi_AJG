#ifndef _REVERSE_HPP_
#define _REVERSE_HPP_
#include "AbilityCommand.hpp"
#include "../../utils/ListOfThing.hpp"

class Reverse : public AbilityCommand {
    public:
        Reverse(string, string);            // user defined ctor

        void execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};

#endif