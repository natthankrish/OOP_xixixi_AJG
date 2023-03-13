#include "Help.hpp"
#include <iostream>

Help::Help(string type, string name) : OrdinaryCommand(type, name){
}

bool Help::continueToNextPlayer(){
    return false;
}

void Help::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank){
    cout << "PUSAT BANTUAN" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Masih under construction" << endl;
    cout << "---------------------------------------" << endl;
}
