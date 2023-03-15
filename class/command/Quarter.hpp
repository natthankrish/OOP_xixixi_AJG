#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_

#include "AbilityCommand.hpp"

class Quarter : public AbilityCommand {
    public:
        Quarter(string, string);            // user defined ctor

        void execute(TableCard&, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};
#endif