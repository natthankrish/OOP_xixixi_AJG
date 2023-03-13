#include "Quadruple.hpp"
#include <iostream>

//======== Quadruple ========
Quadruple::Quadruple(string type, string name) : AbilityCommand(type, name){
}   

void Quadruple::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quadruple");
        //execution
        
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "QUADRUPLE." << endl;
    }

//         cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan QUADRUPLE! Point hadiah naik dari " << prize;
//         prize *= 4; 
//         cout << " menjadi " << prize << endl;
//             int i = 0;
}

bool Quadruple::continueToNextPlayer(List<Player>& listPlayer, int playeridx){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quadruple");
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}