#include "Swap.hpp"
#include <iostream>

//======== Swap ========
Swap::Swap(string type, string name) : AbilityCommand(type, name){
}   

void Swap::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending) {

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
        int j = 1;
        for(int i = 0; i < listPlayer.getNeff(); i++){
            if (i != playeridx - 1) {
                cout << j << ". " << listPlayer.getElement(i).getName() << endl;
                j++;
            }
        }
        cout << "Pilih angka: ";
        cin >> choice1; 
         
        if(choice1 >= playeridx) {
            choice1++;
        }
        cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar:" << endl;
        int k = 1;
        for(int i = 0 ; i < listPlayer.getNeff(); i++){
            if(i != playeridx -1 && i != choice1-1) {
                cout << k << ". " << listPlayer.getElement(i).getName() << endl;
                k++;
            }
        }
        cout << "Pilih angka: ";
        cin >> choice2;

        if (choice2 >= choice1) {
            choice2++;
        }
        if(choice2 >= playeridx) {
            choice2++;
        }
        
        cout << choice1;
        cout << "Silahkan pilih kartu kanan/kiri " << listPlayer.getElement(choice1-1).getName() << ":" << endl;
        cout << "1. Kiri" << endl;
        cout << "2. Kanan" << endl;
        cout << "Pilih angka: ";
        cin >> pickCard1;

        NumberCard card1;
        if (pickCard1 == 1) {
            card1 = listPlayer.getElement(choice1-1).getPairOfCards().first;
        } else if (pickCard1 == 2) {
            card1 = listPlayer.getElement(choice1-1).getPairOfCards().second; 
        }

        cout << choice2;
        cout << "Silahkan pilih kartu kanan/kiri " << listPlayer.getElement(choice2-1).getName() << ":" << endl;
        cout << "1. Kiri" << endl;
        cout << "2. Kanan" << endl;
        cout << "Pilih angka: ";
        cin >> pickCard2;

        NumberCard card2;
        if (pickCard2 == 1) {
            card2 = listPlayer.getElement(choice2-1).getPairOfCards().first;
        } else if (pickCard2 == 2) {
            card2 = listPlayer.getElement(choice2-1).getPairOfCards().second; 
        }

        // cout << "card1 : " << card1.getNumber() << " " << card1.getColor() << endl;
        // cout << "card2 : " << card2.getNumber() << " " << card2.getColor() << endl;

        listPlayer[choice1-1]-card1;
        listPlayer[choice2-1]-card2;

        listPlayer[choice1-1]+card2;
        listPlayer[choice2-1]+card1;
        
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
        AbilityCard temp = listPlayer[playeridx-1]-listPlayer[playeridx-1].getAbilityCard(); 
        abilitycardsbank + temp;
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    } catch (PlayerCardIsDeactivatedException e) {
        return false;
    }
}