#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_
#include "AbilityCommand.hpp"

class Quarter : public AbilityCommand {
    public:
        Quarter(string, string);            // user defined ctor

        void execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank);
        bool continueToNextPlayer();
};

#endif