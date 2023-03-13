#ifndef _DOUBLE_HPP_
#define _DOUBLE_HPP_
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class Double : public OrdinaryCommand {
    public:
        Double(string, string);             // user defined ctor

        void execute(List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);
        bool continueToNextPlayer();


};

#endif