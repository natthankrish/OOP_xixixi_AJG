#ifndef MYCARD_HPP
#define MYCARD_HPP
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class MyCard : public ordinaryCommand {
    private:

    public:
        MyCard(string, string);

        bool continueToNextPlayer();
        void execute(List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);
};

#endif
