#include "Help.hpp"
#include <iostream>

Help::Help(string type, string name) : OrdinaryCommand(type, name){
}

bool Help::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}

void Help::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool& ascending){
    cout << "PUSAT BANTUAN" << endl;
    cout << "---------------------------------------" << endl;
    cout << "NEXT" << endl;
    cout << "DOUBLE" << endl;
    cout << "HALF" << endl;
    cout << "MYCARD" << endl;
    cout << "CHECKTABLECARD" << endl;
    if (listPlayer[playeridx-1].getAbilityCard().getAbilityName() != "none"){
        cout << listPlayer[playeridx-1].getAbilityCard().getAbilityName() <<endl;
    }
    cout << "---------------------------------------" << endl;
}
