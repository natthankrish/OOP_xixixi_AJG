#include "Switch.hpp"
#include <iostream>

//======== Switch ========
Switch::Switch(string type, string name) : AbilityCommand(type, name){

}   

void Switch::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    int choice;
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Switch");
        playerCardIsDeactivated(listPlayer, playeridx);
        //execution
        cout << listPlayer.getElement(playeridx-1).getName()<< " melakukan switch!" << endl;
        cout << "Kartumu sekarang adalah: " << endl;
        cout << listPlayer.getElement(playeridx-1).getPairOfCards().first.getNumber() << " (" << listPlayer.getElement(playeridx-1).getPairOfCards().first.getColor() << ") && " <<  
                listPlayer.getElement(playeridx-1).getPairOfCards().second.getNumber() << " (" << listPlayer.getElement(playeridx-1).getPairOfCards().second.getColor() << endl;

        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        int j = 1;
        for(int i = 0; i < listPlayer.getNeff(); i++){
            if (i != playeridx - 1) {
                cout << j << ". " << listPlayer.getElement(i).getName() << endl;
                j++;
            }
        }
        cout << "Pilih angka: ";
        cin >> choice; 

        if(choice >= playeridx) {
            choice++;
        }
        pair <NumberCard, NumberCard> temp = listPlayer.getElement(playeridx-1).getPairOfCards();

        listPlayer[playeridx-1]-listPlayer.getElement(playeridx-1).getPairOfCards().second;
        listPlayer[playeridx-1]-listPlayer.getElement(playeridx-1).getPairOfCards().first;
        
        listPlayer[playeridx-1]+listPlayer.getElement(choice-1).getPairOfCards().first;
        listPlayer[playeridx-1]+listPlayer.getElement(choice-1).getPairOfCards().second;

        listPlayer[choice-1]-listPlayer.getElement(choice-1).getPairOfCards().second;
        listPlayer[choice-1]-listPlayer.getElement(choice-1).getPairOfCards().first;
        
        listPlayer[choice-1]+temp.first;
        listPlayer[choice-1]+temp.second;


        cout << "Kedua kartu pemain " << listPlayer.getElement(choice-1).getName() << " telah ditukar dengan " << listPlayer.getElement(playeridx-1).getName() << "!" << endl;
        cout << "Kartumu sekarang adalah: " << endl;
        cout << listPlayer.getElement(playeridx-1).getPairOfCards().first.getNumber() << " (" << listPlayer.getElement(playeridx-1).getPairOfCards().first.getColor() << ") && " <<  
                listPlayer.getElement(playeridx-1).getPairOfCards().second.getNumber() << " (" << listPlayer.getElement(playeridx-1).getPairOfCards().second.getColor() << ")" << endl;

        
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "SWITCH." << endl;
    } catch (PlayerCardIsDeactivatedException e) {
        cout << e.what() << endl;
    }
}

bool Switch::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Switch");
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