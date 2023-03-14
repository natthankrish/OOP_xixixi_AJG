#ifndef _CHANGEPLAYERCARD_HPP_
#define _CHANGEPLAYERCARD_HPP_

#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

// #include "../inventory/Player.cpp"
// #include "../../utils/ListOfThing.cpp"
// #include "../Card/Card.cpp"
// #include "../Card/NumberCard.cpp"
// #include "../Card/AbilityCard.cpp"
// #include "../inventory/InventoryHolder.cpp"
// #include "Command.cpp"

class ChangePlayerCard : public OrdinaryCommand {
    private:

    public:
        ChangePlayerCard(string, string);             // user defined ctor

        void execute(TableCard&, List<Player>&, int, int&, CardsBank&, AbilityCardsBank&, bool);
        bool continueToNextPlayer(List<Player>&, int, AbilityCardsBank&);
        int stringToInt(string);
        bool isNum(string);
};

#endif