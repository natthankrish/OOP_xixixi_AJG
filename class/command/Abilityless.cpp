#include "Abilityless.hpp"
#include <iostream>

//======== Abilityless ========
Abilityless::Abilityless(string type, string name) : AbilityCommand(type, name){
}   

void Abilityless::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Abilityless");
        doAllOtherPlayersHaveUsedTheirCards(listPlayer, playeridx);
        //execution
        int choice;
        cout << listPlayer.getElement(playeridx-1).getName()<< " akan mematikan kartu ability lawan!" << endl;
        cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan: " << endl;
        
        int j = 1;
        for(int i = 1 ; i <= listPlayer.getNeff(); i++){
            if(i != playeridx) {
                cout << j << ". " << listPlayer.getElement(i-1).getName() << endl;
                j++;
            }
        }
        cin >> choice;

        if(listPlayer.getElement(choice-1).getAbilityCard().getAbilityName() == "none") {
            cout << "Kartu ability " << listPlayer.getElement(choice-1).getName() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia" << endl; 
        } else {
            listPlayer.getElement(choice-1).setAbilityStatus(false);
            cout << "Kartu ability " << listPlayer.getElement(choice-1).getName() << " telah dimatikan." << endl;
        }

    } catch (PlayerDoesNotHaveCardException e) {
        cout << e.what() << "ABILITYLESS." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
    } catch (AllOtherPlayersHaveUsedTheirCardsException e) {
        cout << e.what() << endl;
    }
}

bool Abilityless::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Abilityless");
        abilitycardsbank.getElement().push_back(AbilityCard("Abilityless"));
        listPlayer.getElement(playeridx-1).setAbilityCard(AbilityCard("none"));
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}