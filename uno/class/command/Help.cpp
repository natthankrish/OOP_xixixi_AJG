#include "Help.hpp"
#include <iostream>

Help::Help(string type, string name) : OrdinaryCommand(type, name){
}

bool Help::continueToNextPlayer(List<Player>& listPlayer, int& playeridx){
    return false;
}

void Help::execute(TableCard& tablecard, List<Player>& listPlayer, int& playeridx,  CardsBank& cardsbank, bool& ascending, int& cardToPick){
    cout << "         === PUSAT BANTUAN ===         " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Default Command : " <<endl;
    cout << "=> NEXT" << endl;
    cout << "=> THROW" << endl;
    cout << "=> PICK" << endl;
    cout << "=> CHECKTABLECARD" << endl;
    cout << "=> MYCARD" << endl;
    cout << "" << endl;
    cout << "---------------------------------------" << endl;
}
