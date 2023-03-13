#include "Half.hpp"
#include "../Round.hpp"
#include <iostream>

//======== Half ========
Half::Half(string type, string name) : OrdinaryCommand(type, name){
}   

void Half::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    if (prize != 1) {
        cout << listPlayer[playeridx-1].getName() << " melakukan HALF! Point hadiah turun dari " << prize;
        prize *= 0.5; 
        cout << " menjadi " << prize << endl;
    } else {
        cout << listPlayer[playeridx-1].getName() << " melakukan HALF! Sayangnya hadiah sudah mencapai angka 1." << endl;
        cout << "Pengurangan poin dibatalkan. Giliran pemain selanjutnya." << endl;
    }
}
bool Half::continueToNextPlayer(List<Player>& listPlayer, int playeridx, AbilityCardsBank& abilitycardsbank){
    return true;
}