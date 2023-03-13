#include "Command.hpp"
#include <iostream>

using namespace std;

//======== command ========
Command::Command(string type, string name): type(type), name(name) {
}

void Command::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout << "Masukan salah! Ketik HELP untuk bantuan." << endl;
    cout << "Sekarang masih giliran pemain " << listPlayer[playeridx-1].getName() << endl;
}

bool Command::continueToNextPlayer(){
    return false;
}

