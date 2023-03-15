#ifndef CHECKTABLE_HPP
#define CHECKTABLE_HPP

#include "OrdinaryCommand.hpp"
#include "../inventory/CardsBank.hpp"

class CheckTable : public OrdinaryCommand {
    public:
        CheckTable(string, string);

        bool continueToNextPlayer(List<Player>& listPlayer, int& playeridx);
        void execute(TableCard& tablecard, List<Player>&, int&, CardsBank&, bool&, int&);
};

#endif
