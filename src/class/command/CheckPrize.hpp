#ifndef CHECKPRIZE_HPP
#define CHECKPRIZE_HPP
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class CheckPrize : public OrdinaryCommand {
    private:

    public:
        CheckPrize(string, string);

        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
        void execute(TableCard&, List<Player>&, int, long long int&, CardsBank&, AbilityCardsBank&, bool&);
};

#endif
