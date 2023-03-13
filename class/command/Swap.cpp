#include "Swap.hpp"
#include <iostream>

//======== Swap ========
Swap::Swap(string type, string name) : AbilityCommand(type, name){
}   

void Swap::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Swap");
        //execution
        
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "SWAP." << endl;
    }
}

bool Swap::continueToNextPlayer(List<Player>& listPlayer, int playeridx){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Swap");
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}