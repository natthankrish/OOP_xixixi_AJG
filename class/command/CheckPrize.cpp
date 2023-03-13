#include "CheckPrize.hpp"

CheckPrize::CheckPrize(string type, string name) : ordinaryCommand("ordinary", "double"){   

}

bool CheckPrize::continueToNextPlayer(){
    return false;
}
void CheckPrize::execute(List<Player>& listPlayer, int playeridx, int& prize){
    cout << "Hadiah Game pada saat ini adalah " << prize << endl;
    cout << "Sekarang masih giliran pemain " << listPlayer[playeridx-1].getName() << endl;
}
