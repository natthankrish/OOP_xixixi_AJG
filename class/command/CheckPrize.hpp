#ifndef CHECKPRIZE_HPP
#define CHECKPRIZE_HPP
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class CheckPrize : public ordinaryCommand {
    private:

    public:
        CheckPrize(string, string);

        bool continueToNextPlayer();
        void execute(List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);
};

#endif
