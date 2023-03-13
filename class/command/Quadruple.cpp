#include "Quadruple.hpp"
#include <iostream>

//======== Quadruple ========
Quadruple::Quadruple(string type, string name) : AbilityCommand(type, name){
}   

void Quadruple::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quadruple");
        //execution
        cout << listPlayer[playeridx-1].getName() << " melakukan QUDRUPLE! Point hadiah naik dari " << prize;
        prize *= 4; 
        cout << " menjadi " << prize << "!" << endl;
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "QUADRUPLE." << endl;
    }
}

bool Quadruple::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quadruple");
        abilitycardsbank.getElement().push_back(AbilityCard("Quadruple"));
        listPlayer.getElement(playeridx-1).setAbilityCard(AbilityCard("none"));
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}