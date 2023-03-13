#ifndef _HALF_HPP_
#define _HALF_HPP_
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class Half : public OrdinaryCommand {
    public:
        Half(string, string);           // user defined ctor

        void execute(List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);
        bool continueToNextPlayer();

};

#endif