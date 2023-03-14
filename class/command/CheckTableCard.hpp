#ifndef CHECKTABLECARD_HPP
#define CHECKTABLECARD_HPP
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"
#include "../inventory/TableCard.hpp"

class CheckTableCard : public OrdinaryCommand {
    private:

    public:
        CheckTableCard(string, string);

        bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
        void execute(TableCard&, List<Player>&, int, int&, CardsBank&, AbilityCardsBank&, bool&);
};

#endif
