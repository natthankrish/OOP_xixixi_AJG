#ifndef _THROW_HPP_
#define _THROW_HPP_

#include "Command.hpp"
#include "OrdinaryCommand.hpp"
#include "../inventory/CardsBank.hpp"
#include "../Card/NumberCard.hpp"

class Throw : public OrdinaryCommand {
    private:
        bool success;
    public:
        Throw(string, string);   
        void execute(TableCard&, List<Player>&, int&, CardsBank&, bool&, int&);
        bool continueToNextPlayer(List<Player>& listPlayer, int& playeridx);
};

#endif