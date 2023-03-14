#ifndef MYCARD_HPP
#define MYCARD_HPP
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class MyCard : public OrdinaryCommand {
    public:
        MyCard(string, string);

        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
        void execute(TableCard& tablecard, List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);
};

#endif
