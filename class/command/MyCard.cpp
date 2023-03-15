#include "MyCard.hpp"

MyCard::MyCard(string type, string name) : OrdinaryCommand("ordinary", "double"){   
}

bool MyCard::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}

void MyCard::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending){
    cout << "---------------------------------------" <<endl;
    cout << "        == " << "Player " << playeridx << "'s Cards ==        " <<endl;
    listPlayer[playeridx-1].seeCard();
    cout << "---------------------------------------" <<endl;
    // cout << "Sekarang masih giliran pemain " << listPlayer[playeridx-1].getName() << endl;
}
