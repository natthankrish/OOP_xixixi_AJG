#include "CheckPrize.hpp"

CheckPrize::CheckPrize(string type, string name) : OrdinaryCommand("ordinary", "check prize"){   

}

bool CheckPrize::continueToNextPlayer(){
    return false;
}
void CheckPrize::execute(int& prize, Round round){
    cout << "Hadiah Game pada saat ini adalah " << prize << endl;
    cout << "Sekarang masih giliran " << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << endl;
}

bool CheckPrize::continueToNextPlayer(){
    return false;
}