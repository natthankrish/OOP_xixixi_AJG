#include "Reroll.hpp"
#include <iostream>

//======== Reroll ========
Reroll::Reroll(string type, string name) : AbilityCommand(type, name){
}

void Reroll::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Re-roll");
        //execution

    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "REROLL." << endl;
    }
}

bool Reroll::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Re-roll");
        abilitycardsbank.getElement().push_back(AbilityCard("Re-roll"));
        listPlayer.getElement(playeridx-1).setAbilityCard(AbilityCard("none"));

        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}