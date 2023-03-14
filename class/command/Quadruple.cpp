#include "Quadruple.hpp"
#include <iostream>

//======== Quadruple ========
Quadruple::Quadruple(string type, string name) : AbilityCommand(type, name){
}   

void Quadruple::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool ascending) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quadruple");
        playerCardIsDeactivated(listPlayer, playeridx);

        //execution
        cout << listPlayer[playeridx-1].getName() << " melakukan QUDRUPLE! Point hadiah naik dari " << prize;
        prize *= 4; 
        cout << " menjadi " << prize << "!" << endl;
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "QUADRUPLE." << endl;
    } catch (PlayerCardIsDeactivatedException e) {
        cout << e.what() << endl;
    }
}

bool Quadruple::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quadruple");
        playerCardIsDeactivated(listPlayer, playeridx);
        AbilityCard temp = listPlayer[playeridx-1]-listPlayer[playeridx-1].getAbilityCard(); 
        abilitycardsbank + temp;
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    } catch (PlayerCardIsDeactivatedException e) {
        return false;
    }
}