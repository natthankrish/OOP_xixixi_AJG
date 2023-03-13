#include "Switch.hpp"
#include <iostream>

//======== Switch ========
Switch::Switch(string type, string name) : AbilityCommand(type, name){

}   

void Switch::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout<<"Switch execute\n";
}

bool Switch::continueToNextPlayer(){
    return false;
}