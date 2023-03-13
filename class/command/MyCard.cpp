#include "MyCard.hpp"

MyCard::MyCard(string type, string name) : ordinaryCommand("ordinary", "double"){   

}

bool MyCard::continueToNextPlayer(){
    return false;
}

void MyCard::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank){
    listPlayer[playeridx-1].seeCard();
    cout << "Sekarang masih giliran pemain " << listPlayer[playeridx-1].getName() << endl;
}
