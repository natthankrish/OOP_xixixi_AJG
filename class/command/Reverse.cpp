#include "Reverse.hpp"
#include <iostream>

//======== Reverse ========
Reverse::Reverse(string type, string name) : AbilityCommand(type, name){
}   

void Reverse::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Reverse");
        playerCardIsDeactivated(listPlayer, playeridx);
        //execution
        cout << listPlayer.getElement(playeridx-1).getName()<< " melakukan reverse!" << endl;
        ascending = false;

        // //print out 
        // cout << "(sisa) urutan eksekusi giliran ini: ";

        // int i = playeridx;
        // for(i - 1 ; i == playeridx; i--) {
        //     if(!listPlayer.getElement(i-1).gethavePlayed()){
        //         cout << listPlayer.getElement(i-1).getName() << " ";
        //     }
        // }
        // cout << endl;
        // cout <<"urutan eksekusi giliran selanjutnya: ";
        // int j = playeridx;
        // for(j - 1 ; j == playeridx; j--) {
        //     if(!listPlayer.getElement(j-1).gethavePlayed()){
        //         cout << listPlayer.getElement(j-1).getName() << " ";
        //     }
        // }
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "REVERSE." << endl;
    } catch (PlayerCardIsDeactivatedException e) {
        cout << e.what() << endl;
    }
}
bool Reverse::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Reverse");
        playerCardIsDeactivated(listPlayer, playeridx);
        AbilityCard temp = listPlayer[playeridx-1]-listPlayer[playeridx-1].getAbilityCard(); 
        abilitycardsbank + temp;
        return false;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;    
    } catch (PlayerCardIsDeactivatedException e) {
        return false;
    }
    
}