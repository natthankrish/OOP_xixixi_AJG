#include "Help.hpp"
#include <iostream>

Help::Help(string type, string name) : OrdinaryCommand(type, name){
}

bool Help::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return false;
}

void Help::execute(TableCard& tablecard, List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, bool ascending){
    cout << "PUSAT BANTUAN" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Masih under construction" << endl;
    cout << "---------------------------------------" << endl;
}
