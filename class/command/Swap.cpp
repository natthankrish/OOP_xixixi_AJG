#include "Swap.hpp"
#include <iostream>

//======== Swap ========
Swap::Swap(string type, string name) : AbilityCommand(type, name){
}   

void Swap::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {

    try{
        int choice1;
        int choice2;
        int pickCard1;
        int pickCard2;

        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Swap");
        playerCardIsDeactivated(listPlayer, playeridx);
        //execution
        cout << listPlayer.getElement(playeridx-1).getName()<< " melakukan SWAPCARD." << endl;

        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for(int i = 1 ; i <= listPlayer.getNeff(); i++){
            cout << i << ". " << listPlayer.getElement(i).getName() << endl;
        }
        cin >> choice1; 
        
        cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar:" << endl;
        int j = 1;
        for(int i = 1 ; i <= listPlayer.getNeff(); i++){
            if(i != choice1) {
                cout << j << ". " << listPlayer.getElement(i).getName() << endl;
                j++;
            }
        }
        cin >> choice2; 

        if (choice2 >= choice1) {
            choice2++;
        }

        cout << "Silahkan pilih kartu kanan/kiri " << listPlayer.getElement(choice1).getName() << ":" << endl;
        cout << "1. Kiri" << endl;
        cout << "2. Kanan" << endl;
        cin >> pickCard1;

        NumberCard card1;
        if (pickCard1 == 1) {
            card1 = listPlayer.getElement(choice1).getPairOfCards().first;
        } else if (pickCard1 == 2) {
            card1 = listPlayer.getElement(choice1).getPairOfCards().second; 
        }

        cout << "Silahkan pilih kartu kanan/kiri " << listPlayer.getElement(choice2).getName() << ":" << endl;
        cout << "1. Kiri" << endl;
        cout << "2. Kanan" << endl;
        cin >> pickCard2;

        NumberCard card2;
        if (pickCard2 == 1) {
            card2 = listPlayer.getElement(choice2).getPairOfCards().first;
        } else if (pickCard2 == 2) {
            card2 = listPlayer.getElement(choice2).getPairOfCards().second; 
        }

        listPlayer.getElement(choice1)-card1;
        listPlayer.getElement(choice2)-card2;

        listPlayer.getElement(choice1)+card2;
        listPlayer.getElement(choice2)+card1;
        
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "SWAP." << endl;
    } catch (PlayerCardIsDeactivatedException e) {
        cout << e.what() << endl;
    }
}

bool Swap::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Swap");
        playerCardIsDeactivated(listPlayer, playeridx);
        // abilitycardsbank.getElement().push_back(AbilityCard("Swap"));
        listPlayer.getElement(playeridx-1).setAbilityCard(AbilityCard("none"));
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    } catch (PlayerCardIsDeactivatedException e) {
        return false;
    }
}