#include "Double.hpp"
#include <iostream>

//======== Double ========
Double::Double(string type, string name) : OrdinaryCommand(type, name){
}   

void Double::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending) {
    cout << listPlayer[playeridx-1].getName() << " melakukan DOUBLE! Point hadiah naik dari " << prize;
    prize *= 2; 
    cout << " menjadi " << prize << "!" << endl;
}

bool Double::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return true;
}
