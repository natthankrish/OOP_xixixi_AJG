#include "Next.hpp"
#include <iostream>

//======== Next ========  
Next::Next(string type, string name) : OrdinaryCommand(type, name){
}    

void Next::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout << "Giliran dilanjut ke player selanjutnya." << endl;
}

bool Next::continueToNextPlayer(){
    return true;
}