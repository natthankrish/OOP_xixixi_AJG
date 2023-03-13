#include "Switch.hpp"
#include <iostream>

//======== Switch ========
Switch::Switch(string type, string name) : AbilityCommand(type, name){

}   

void Switch::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
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
        for(int i = 1 ; i <= listPlayer.getNeff(); i++){
            cout << i << ". " << listPlayer.getElement(i).getName() << endl;
        }
        cin >> choice; 

        pair <NumberCard, NumberCard> temp = listPlayer.getElement(playeridx-1).getPairOfCards();

        listPlayer.getElement(playeridx-1)-listPlayer.getElement(playeridx-1).getPairOfCards().second;
        listPlayer.getElement(playeridx-1)-listPlayer.getElement(playeridx-1).getPairOfCards().first;
        
        listPlayer.getElement(playeridx-1)+listPlayer.getElement(choice).getPairOfCards().first;
        listPlayer.getElement(playeridx-1)+listPlayer.getElement(choice).getPairOfCards().second;

        listPlayer.getElement(choice)-listPlayer.getElement(choice).getPairOfCards().second;
        listPlayer.getElement(choice)-listPlayer.getElement(choice).getPairOfCards().first;
        
        listPlayer.getElement(choice)+temp.first;
        listPlayer.getElement(choice)+temp.second;


        cout << "Kedua kartu pemain" << listPlayer.getElement(choice).getName() << " telah ditukar dengan " << listPlayer.getElement(playeridx-1).getName() << "!" << endl;
        cout << "Kartumu sekarang adalah: " << endl;
        cout << listPlayer.getElement(playeridx-1).getPairOfCards().first.getNumber() << " (" << listPlayer.getElement(playeridx-1).getPairOfCards().first.getColor() << ") && " <<  
                listPlayer.getElement(playeridx-1).getPairOfCards().second.getNumber() << " (" << listPlayer.getElement(playeridx-1).getPairOfCards().second.getColor() << endl;

        
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
        // abilitycardsbank.getElement().push_back(AbilityCard("Switch"));
        listPlayer.getElement(playeridx-1).setAbilityStatus(false);
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    } catch (PlayerCardIsDeactivatedException e) {
        return false;
    }
}