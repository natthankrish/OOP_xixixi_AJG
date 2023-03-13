#ifndef _ABILITYLESS_HPP_
#define _ABILITYLESS_HPP_
#include "AbilityCommand.hpp"

class Abilityless : public AbilityCommand {
    public:
        Abilityless(string, string);                // user defined ctor
        void execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx);
};

#endif 