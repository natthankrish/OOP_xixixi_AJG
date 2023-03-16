#include "MyCard.hpp"

MyCard::MyCard(string type, string name) : OrdinaryCommand("ordinary", "double"){   
}

bool MyCard::continueToNextPlayer(List<Player>& listPlayer, int& playeridx){
    return false;
}

void MyCard::execute(TableCard& tablecard, List<Player>& listPlayer, int& playeridx, CardsBank& cardsbank, bool& ascending, int& cardToPick){
    cout << "---------------------------------------" <<endl;
    cout << "        == " << "Player " << playeridx << "'s Cards ==        " <<endl;
    listPlayer[playeridx-1].seeCard();
    cout << "---------------------------------------" <<endl;
}
