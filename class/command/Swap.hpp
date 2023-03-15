#ifndef _SWAP_HPP_
#define _SWAP_HPP_
#include "AbilityCommand.hpp"
#include "../../utils/ListOfThing.hpp"

class Swap : public AbilityCommand {
    public:
        Swap(string, string);             // user defined ctor

        void execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};

#endif