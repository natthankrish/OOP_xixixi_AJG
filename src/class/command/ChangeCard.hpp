#ifndef _CHANGECARD_HPP_
#define _CHANGECARD_HPP_

#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"
#include "../inventory/InventoryException.hpp"
#include "CardException.hpp"
#include "../../utils/ListOfThing.hpp"

class ChangeCard : public OrdinaryCommand {
    private:

    public:
        ChangeCard(string, string);             // user defined ctor

        void execute(TableCard&, List<Player>&, int, long long int&, CardsBank&, AbilityCardsBank&, bool&);
        bool continueToNextPlayer(List<Player>&, int, AbilityCardsBank&);
        int stringToInt(string);
        bool isNum(string);
        bool isInCardsBank();
};

#endif