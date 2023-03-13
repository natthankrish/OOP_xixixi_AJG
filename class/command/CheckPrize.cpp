#include "CheckPrize.hpp"

CheckPrize::CheckPrize(string type, string name) : OrdinaryCommand("ordinary", "double"){   

}

bool CheckPrize::continueToNextPlayer(){
    return false;
}
void CheckPrize::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank){
    cout << "Hadiah Game pada saat ini adalah " << prize << endl;
    cout << "Sekarang masih giliran pemain " << listPlayer[playeridx-1].getName() << endl;
}
