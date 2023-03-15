#include "CheckTableCard.hpp"

CheckTableCard::CheckTableCard(string type, string name) : OrdinaryCommand("ordinary", "checktablecard"){   

}

bool CheckTableCard::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}
void CheckTableCard::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending){
    cout << "---------------------------------------" <<endl;
    cout << "           == Table Cards ==           " <<endl;
    tablecard.seeCard();
    cout << "---------------------------------------" <<endl;
}