#include "OrdinaryCommand.hpp"
#include <iostream>

//======== ordinaryCommand ========
OrdinaryCommand::OrdinaryCommand(string type, string name) : Command(type, name) {
}  

void OrdinaryCommand::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending) {
    cout<<"ordinary Command execute\n";
}

bool OrdinaryCommand::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}
