#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_
#include "AbilityCommand.hpp"

class Quadruple : public AbilityCommand {
    public:
        Quadruple(string, string);              // user defined ctor

        void execute(TableCard&, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool ascending);
        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};

#endif