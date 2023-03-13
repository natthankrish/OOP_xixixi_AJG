#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "../inventory/Player.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"
#include "../inventory/TableCard.hpp"

using namespace std;

class Command {
    private:
        string type;
        string name;
    
    public:
        Command(string, string);            // user defined ctor

        virtual void execute(TableCard& tablecard, List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);
        virtual bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);
};

#endif