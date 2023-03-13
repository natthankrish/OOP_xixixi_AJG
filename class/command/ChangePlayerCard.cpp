#include "ChangePlayerCard.hpp"

ChangePlayerCard::ChangePlayerCard(string type, string name) : OrdinaryCommand("ordinary", "changenum"){   

}

bool ChangePlayerCard::continueToNextPlayer(){
    return false;
}
void ChangePlayerCard::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank){
    // TO DOOO
    cout << "Test" << endl;
}