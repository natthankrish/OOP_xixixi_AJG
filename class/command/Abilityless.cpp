#include "Abilityless.hpp"
#include <iostream>

//======== Abilityless ========
Abilityless::Abilityless(string type, string name) : AbilityCommand(type, name){
}   

void Abilityless::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool ascending) {
    int choice;
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Abilityless");
        doAllOtherPlayersHaveUsedTheirCards(listPlayer, playeridx-1);
        //execution
        cout << listPlayer.getElement(playeridx-1).getName()<< " akan mematikan kartu ability lawan!" << endl;
        cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan: " << endl;
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
        playerCardIsUsed(listPlayer, choice-1);
        listPlayer[choice-1].setAbilityStatus(false);
        cout << "Kartu ability " << listPlayer.getElement(choice-1).getName() << " telah dimatikan." << endl;
    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "ABILITYLESS." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
    } catch (AllOtherPlayersHaveUsedTheirCardsException e) {
        cout << e.what() << endl;
    } catch (PlayerCardIsUsedException e) {
        cout << "Kartu ability " << listPlayer.getElement(choice).getName() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia" << endl;
    }
}

bool Abilityless::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Abilityless");
        AbilityCard temp = listPlayer[playeridx-1]-listPlayer[playeridx-1].getAbilityCard(); 
        abilitycardsbank + temp;
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}