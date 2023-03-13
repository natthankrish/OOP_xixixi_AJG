#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_
#include "AbilityCommand.hpp"

class Switch : AbilityCommand {
    public:
        Switch(string, string);             // user defined ctor

        void execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx);
};

#endif