#include "Reroll.hpp"
#include <iostream>

//======== Reroll ========
Reroll::Reroll(string type, string name) : AbilityCommand(type, name){
}

void Reroll::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Re-roll");
        playerCardIsDeactivated(listPlayer, playeridx);
        //execution
        cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
        NumberCard card1 = listPlayer.getElement(playeridx-1).getPairOfCards().second;
        NumberCard card2 = listPlayer.getElement(playeridx-1).getPairOfCards().second;

        listPlayer.getElement(playeridx-1)+cardsbank.getElementAt(0);
        cardsbank-cardsbank.getElementAt(0);
        listPlayer.getElement(playeridx-1)+cardsbank.getElementAt(0);
        cardsbank-cardsbank.getElementAt(0);

        cardsbank+card1;
        cardsbank+card2;

        cout << "Kamu mendapat 2 kartu baru yaitu:";
        cout << "1. " << listPlayer.getElement(playeridx-1).getPairOfCards().first.getNumber() << " " << listPlayer.getElement(playeridx-1).getPairOfCards().first.getColor() << endl; 
        cout << "2. " << listPlayer.getElement(playeridx-1).getPairOfCards().second.getNumber() << " " << listPlayer.getElement(playeridx-1).getPairOfCards().second.getColor() << endl; 



    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "REROLL." << endl;
    } catch (PlayerCardIsDeactivatedException e) {
        cout << e.what() << endl;
    }
}

bool Reroll::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Re-roll");
        playerCardIsDeactivated(listPlayer, playeridx);
        // abilitycardsbank.getElement().push_back(AbilityCard("Re-roll"));
        listPlayer.getElement(playeridx-1).setAbilityStatus(false);
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    } catch (PlayerCardIsDeactivatedException e) {
        return false;
    }
}