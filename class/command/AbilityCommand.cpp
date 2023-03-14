#include "AbilityCommand.hpp"
#include <iostream>

//======== abilityCommand ========
AbilityCommand::AbilityCommand(string type, string name) : Command(type, name){
}

void AbilityCommand::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout<<"abilityCommand execute\n";
}

bool AbilityCommand::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}

void AbilityCommand::doesPlayerHaveAbilityCard(List<Player>& listPlayer, int playeridx, string cardName){
    if (listPlayer.getElement(playeridx - 1).getAbilityCard().getAbilityName() != cardName) {
        throw PlayerDoesNotHaveCardException();
    }
}

void AbilityCommand::doAllOtherPlayersHaveUsedTheirCards(List<Player>& listPlayer, int playeridx){
    
    for(int i = 1 ; i <= listPlayer.getNeff(); i++){
        if(i != playeridx && listPlayer.getElement(i-1).getAbilityCard().getAbilityName() != "none"){
            throw AllOtherPlayersHaveUsedTheirCardsException();
        }
    }

}

void AbilityCommand::playerCardIsUsed(List<Player>& listPlayer, int playeridx){
    if (!listPlayer.getElement(playeridx - 1).getAbilityStatus()) {
        throw PlayerDoesNotHaveCardException();
    }
}
void AbilityCommand::playerCardIsDeactivated(List<Player>& listPlayer, int playeridx){
    if (!listPlayer.getElement(playeridx - 1).getAbilityStatus()) {
        throw PlayerDoesNotHaveCardException();
    }
}
