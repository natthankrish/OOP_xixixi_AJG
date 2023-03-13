#include "ChangePlayerCard.hpp"

ChangePlayerCard::ChangePlayerCard(string type, string name) : ordinaryCommand("ordinary", "changenum"){   

}

bool ChangePlayerCard::continueToNextPlayer(){
    return false;
}
void ChangePlayerCard::execute(List<Player>& listPlayer, int playeridx, int& prize){
    // TO DOOO
    cout << "Test" << endl;
}