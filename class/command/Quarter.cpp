#include "Quarter.hpp"
#include <iostream>

//======== Quarter ========
Quarter::Quarter(string type, string name) : AbilityCommand(type, name){
}

void Quarter::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quarter");
        //execution
        
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "QUATER" << endl;
    }

    // if (prize >= 4) {
    //     cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan QUARTER! Point hadiah turun dari " << prize;
    //     prize *= 0.25; 
    //     cout << " menjadi " << prize << endl;
    // } else if (prize == 2) {
    //     cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan QUARTER! Sayangnya point hadiah hanya turun dari " << prize;
    //     prize *= 0.5; 
    //     cout << " menjadi " << prize << endl;
    // } else {
    //     cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan QUARTER! Sayangnya hadiah sudah mencapai angka 1." << endl;
    //     cout << "Pengurangan poin dibatalkan. Giliran pemain selanjutnya." << endl;
    // }
}

bool Quarter::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quarter");
        abilitycardsbank.getElement().push_back(AbilityCard("Quarter"));
        listPlayer.getElement(playeridx-1).setAbilityCard(AbilityCard("none"));
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}