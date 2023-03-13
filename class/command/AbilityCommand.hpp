#ifndef _ABILITY_COMMAND_HPP_
#define _ABILITY_COMMAND_HPP_
#include "Command.hpp"
#include "../inventory/Player.hpp"
#include "../../utils/ListOfThing.hpp"
#include "../Round.hpp"
#include "CardException.hpp"

class AbilityCommand : public Command {
    public:
        AbilityCommand(string, string);                     // user defined ctor
        
        virtual void execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank);
        virtual bool continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank);

        void doesPlayerHaveAbilityCard(List<Player>& listPlayer, int playeridx, string cardName);
        void doAllOtherPlayersHaveUsedTheirCards(List<Player>& listPlayer, int playeridx);
};

#endif