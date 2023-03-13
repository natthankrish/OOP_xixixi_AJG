#include "Reverse.hpp"
#include <iostream>

//======== Reverse ========
Reverse::Reverse(string type, string name) : AbilityCommand(type, name){
}   

void Reverse::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Reverse");
        //execution
        
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "REVERSE." << endl;
    }
}
bool Reverse::continueToNextPlayer(List<Player>& listPlayer, int playeridx){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Reverse");
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}