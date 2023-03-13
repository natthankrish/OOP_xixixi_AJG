#ifndef _REVERSE_HPP_
#define _REVERSE_HPP_
#include "AbilityCommand.hpp"

class Reverse : public AbilityCommand {
    public:
        Reverse(string, string);            // user defined ctor

        void execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx);
};

#endif