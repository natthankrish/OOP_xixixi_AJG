#include "Quarter.hpp"
#include <iostream>

//======== Quarter ========
Quarter::Quarter(string type, string name) : AbilityCommand(type, name){
}

void Quarter::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quarter");
        playerCardIsDeactivated(listPlayer, playeridx);
        //execution
        if (prize >= 4) {
            cout << listPlayer[playeridx-1].getName() << " melakukan QUARTER! Point hadiah turun dari " << prize;
            prize *= 0.25; 
            cout << " menjadi " << prize << "!" << endl;
        } else if (prize == 2) {
            cout << listPlayer[playeridx-1].getName() << " melakukan QUARTER! Sayangnya point hadiah hanya turun dari " << prize;
            prize *= 0.5; 
            cout << " menjadi " << prize << "!" << endl;
        } else {
            cout << listPlayer[playeridx-1].getName() << " melakukan QUARTER! Sayangnya hadiah sudah mencapai angka 1." << endl;
            cout << "Pengurangan poin dibatalkan. Giliran pemain selanjutnya." << endl;
        }
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "QUATER" << endl;
    } catch (PlayerCardIsDeactivatedException e) {
        cout << e.what() << endl;
    }
}

bool Quarter::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Quarter");
        playerCardIsDeactivated(listPlayer, playeridx);
        AbilityCard temp = listPlayer[playeridx-1]-listPlayer.getElement(playeridx-1).getAbilityCard(); 
        abilitycardsbank + temp;
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    } catch (PlayerCardIsDeactivatedException e) {
        return false;
    }
}