#ifndef HELP_HPP
#define HELP_HPP
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class Help : public OrdinaryCommand {
    public:
        Help(string, string);

        bool continueToNextPlayer();
        void execute(List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);      
};

#endif