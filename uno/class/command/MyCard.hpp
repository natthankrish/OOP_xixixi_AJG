#ifndef MYCARD_HPP
#define MYCARD_HPP

#include "OrdinaryCommand.hpp"
#include "../inventory/CardsBank.hpp"

class MyCard : public OrdinaryCommand {
    public:
        MyCard(string, string);

        bool continueToNextPlayer(List<Player>& listPlayer, int& playeridx);
        void execute(TableCard& tablecard, List<Player>&, int&, CardsBank&, bool&, int&);
};

#endif
