#ifndef _CHANGEPLAYERCARD_HPP_
#define _CHANGEPLAYERCARD_HPP_

#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class ChangePlayerCard : public OrdinaryCommand {
    private:

    public:
        ChangePlayerCard(string, string);             // user defined ctor

        void execute(List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);
        bool continueToNextPlayer();


};

#endif