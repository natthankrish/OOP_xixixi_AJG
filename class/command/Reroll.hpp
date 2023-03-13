#ifndef _REROLL_HPP_
#define _REROLL_HPP_
#include "AbilityCommand.hpp"

class Reroll : public AbilityCommand {
    public:
        Reroll(string, string);             // user defined ctor
        
        void execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx);
};

#endif