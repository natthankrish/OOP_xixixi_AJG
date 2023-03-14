#include "MyCard.hpp"

MyCard::MyCard(string type, string name) : OrdinaryCommand("ordinary", "double"){   
}

bool MyCard::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}

void MyCard::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank){
    listPlayer[playeridx-1].seeCard();
    cout << "Sekarang masih giliran pemain " << listPlayer[playeridx-1].getName() << endl;
}
