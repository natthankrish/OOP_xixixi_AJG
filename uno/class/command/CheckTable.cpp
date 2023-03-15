#include "CheckTable.hpp"

CheckTable::CheckTable(string type, string name) : OrdinaryCommand("ordinary", "double"){   
}

bool CheckTable::continueToNextPlayer(List<Player>& listPlayer, int& playeridx){
    return false;
}

void CheckTable::execute(TableCard& tablecard, List<Player>& listPlayer, int& playeridx, CardsBank& cardsbank, bool& ascending, int& cardToPick){
    if (tablecard.Top().getNumber() < 14) {
        cout << "Kartu teratas di meja " << tablecard.Top() << endl;
    } else {
        cout << "Kartu teratas di meja " << tablecard.Top() << "(" << tablecard.Top().getColor() << ")" << endl;
    }
}
