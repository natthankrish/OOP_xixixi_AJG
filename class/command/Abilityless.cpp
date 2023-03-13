#include "Abilityless.hpp"
#include <iostream>

//======== Abilityless ========
Abilityless::Abilityless(string type, string name) : AbilityCommand(type, name){
}   

void Abilityless::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Abilityless");
        //execution
        
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "ABILITYLESS." << endl;
    }
}

bool Abilityless::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Abilityless");
        abilitycardsbank.getElement().push_back(AbilityCard("Abilityless"));
        listPlayer.getElement(playeridx-1).setAbilityCard(AbilityCard("none"));
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}