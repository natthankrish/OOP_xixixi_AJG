#ifndef _NEXT_HPP_
#define _NEXT_HPP_

#include "OrdinaryCommand.hpp"
#include "../Round.hpp"
#include "../inventory/CardsBank.hpp"

class Next : public OrdinaryCommand {
    public:
        Next(string, string);           // user defined ctor

        void execute(TableCard&, List<Player>&, int&, CardsBank&, bool&, int&);
        bool continueToNextPlayer(List<Player>& listPlayer, int& playeridx);
};

#endif