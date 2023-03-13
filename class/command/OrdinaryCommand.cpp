#include "OrdinaryCommand.hpp"
#include <iostream>

//======== ordinaryCommand ========
OrdinaryCommand::OrdinaryCommand(string type, string name) : Command(type, name) {
}  

void OrdinaryCommand::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout<<"ordinary Command execute\n";
}

bool OrdinaryCommand::continueToNextPlayer(){
    return false;
}
