#include "CheckPoint.hpp"

CheckPoint::CheckPoint(string type, string name) : OrdinaryCommand("ordinary", "checkpoint"){   

}

bool CheckPoint::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}
void CheckPoint::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, long long int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending){
    // sorting
    int a = 0;
    for (int j = 0; j < listPlayer.getNeff(); j++) {
        long long int max = listPlayer.getElement(j).getPoint();
        int idxMax = j;
        for (int k = j; k < listPlayer.getNeff(); k++) {
            if (max < listPlayer.getElement(k).getPoint()){
                max = listPlayer.getElement(k).getPoint();
                idxMax = k;
            }
        }
        Player temp;
        temp = listPlayer.getElement(j);  
        listPlayer.setElementAt(j,  listPlayer.getElement(idxMax));
        listPlayer.setElementAt(idxMax, temp);
    } 
    
    cout << "---------------------------------------" <<endl;
    cout << "           == Leaderboard ==           " << endl;
    for(int x = 1; x <= listPlayer.getNeff(); x++) {
        cout << x << ". " << listPlayer.getElement(x-1).getName() << ": " << listPlayer.getElement(x-1).getPoint() << endl;
    }
    cout << "---------------------------------------" <<endl;
}
