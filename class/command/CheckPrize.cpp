#include "CheckPrize.hpp"

CheckPrize::CheckPrize(string type, string name, List<Player> listPlayer) : ordinaryCommand("ordinary", "double",listPlayer){   

}

bool CheckPrize::continueToNextPlayer(){
    return false;
}
void CheckPrize::execute(Round round, int prize){
    cout << "Hadiah Game pada saat ini adalah " << prize << endl;
    cout << "Sekarang masih giliran " << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << endl;
}

bool CheckPrize::continueToNextPlayer(){
    return false;
}