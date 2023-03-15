#include "OrdinaryCommand.hpp"
#include <iostream>

//======== ordinaryCommand ========
OrdinaryCommand::OrdinaryCommand(string type, string name) : Command(type, name) {
}  

void OrdinaryCommand::execute(TableCard& tablecard, List<Player>& listPlayer, int& playeridx, CardsBank& cardsbank, bool& ascending, int& cardToPick) {
    cout<<"ordinary Command execute\n";
}

bool OrdinaryCommand::continueToNextPlayer(List<Player>& listPlayer, int& playeridx){
    return false;
}
