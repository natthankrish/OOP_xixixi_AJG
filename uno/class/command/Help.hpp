#ifndef HELP_HPP
#define HELP_HPP
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class Help : public OrdinaryCommand {
    public:
        Help(string, string);

        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
        void execute(TableCard&, List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);      
};

#endif