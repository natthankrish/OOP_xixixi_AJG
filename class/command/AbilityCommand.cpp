#include "AbilityCommand.hpp"
#include <iostream>

//======== abilityCommand ========
AbilityCommand::AbilityCommand(string type, string name) : Command(type, name){
}

void AbilityCommand::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout<<"abilityCommand execute\n";
}

bool AbilityCommand::continueToNextPlayer(){
    return false;
}
