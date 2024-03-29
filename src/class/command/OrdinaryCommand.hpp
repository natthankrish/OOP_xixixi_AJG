#ifndef _ORDINARY_COMMAND_HPP
#define _ORDINARY_COMMAND_HPP
#include "Command.hpp"
#include "../inventory/Player.hpp"
#include "../../utils/ListOfThing.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class OrdinaryCommand : public Command {
    public:
        OrdinaryCommand(string, string);                    // user defined ctor

        virtual void execute(TableCard&, List<Player>&, int, long long int&, CardsBank&, AbilityCardsBank&, bool&);
        virtual bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};

#endif