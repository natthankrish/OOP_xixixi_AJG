#include "Switch.hpp"
#include <iostream>

//======== Switch ========
Switch::Switch(string type, string name) : AbilityCommand(type, name){

}   

void Switch::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Switch");
        //execution
        
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "SWITCH." << endl;
    }
}

bool Switch::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Switch");
        abilitycardsbank.getElement().push_back(AbilityCard("Switch"));
        listPlayer.getElement(playeridx-1).setAbilityCard(AbilityCard("None"));
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}