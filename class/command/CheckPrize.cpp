#include "CheckPrize.hpp"

CheckPrize::CheckPrize(string type, string name) : OrdinaryCommand("ordinary", "double"){   

}

bool CheckPrize::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}
void CheckPrize::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending){
    cout << "Hadiah Game pada saat ini adalah " << prize << endl;
    cout << "Sekarang masih giliran pemain " << listPlayer[playeridx-1].getName() << endl;
}
