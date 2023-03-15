#ifndef _PICK_HPP_
#define _PICK_HPP_

#include "OrdinaryCommand.hpp"
#include "../inventory/CardsBank.hpp"

class Pick : public OrdinaryCommand {
    public:
        Pick(string, string);           // user defined ctor

        void execute(TableCard&, List<Player>&, int&, CardsBank&, bool&, int&);
        bool continueToNextPlayer(List<Player>& listPlayer, int& playeridx);
};

#endif