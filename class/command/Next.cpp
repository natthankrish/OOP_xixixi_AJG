#include "Next.hpp"
#include <iostream>

//======== Next ========  
Next::Next(string type, string name) : OrdinaryCommand(type, name){
}    

void Next::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending) {
    cout << "Giliran dilanjut ke player selanjutnya." << endl;
}

bool Next::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return true;
}