#include "Abilityless.hpp"
#include <iostream>

//======== Abilityless ========
Abilityless::Abilityless(string type, string name) : AbilityCommand(type, name){
}   

void Abilityless::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    int choice;
    try{
        doesPlayerHaveAbilityCard(listPlayer, playeridx, "Abilityless");
        doAllOtherPlayersHaveUsedTheirCards(listPlayer, playeridx);
        //execution
        cout << listPlayer.getElement(playeridx-1).getName()<< " akan mematikan kartu ability lawan!" << endl;
        cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan: " << endl;
        
        for(int i = 1 ; i <= listPlayer.getNeff(); i++){
            cout << i << ". " << listPlayer.getElement(i).getName() << endl;
        }
        cin >> choice;

        playerCardIsUsed(listPlayer, playeridx);
        listPlayer.getElement(choice-1).setAbilityStatus(false);
        cout << "Kartu ability " << listPlayer.getElement(choice).getName() << " telah dimatikan." << endl;

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
        // abilitycardsbank.getElement().push_back(AbilityCard("Abilityless"));
        listPlayer.getElement(playeridx-1).setAbilityStatus(false);
        return true;
    } catch (PlayerDoesNotHaveCardException e) {
        return false;
    }
}