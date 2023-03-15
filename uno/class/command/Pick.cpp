#include "Pick.hpp"
#include <iostream>

//======== Next ========  
Pick::Pick(string type, string name) : OrdinaryCommand(type, name){
}    

void Pick::execute(TableCard& tablecard, List<Player>& listPlayer, int& playeridx, CardsBank& cardsbank, bool& ascending, int& cardToPick) {
    listPlayer[playeridx-1] + cardsbank.operator--();
}

bool Pick::continueToNextPlayer(List<Player>& listPlayer, int& playeridx){
    return true;
}