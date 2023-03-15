#include "Command.hpp"
#include <iostream>

using namespace std;

//======== command ========
Command::Command(string type, string name): type(type), name(name) {
}

void Command::execute(TableCard& tablecard, List<Player>& listPlayer, int& playeridx, CardsBank& cardsbank, bool& ascending, int& cardToPick) {
    cout << "Masukan salah! Ketik HELP untuk bantuan." << endl;
    cout << "Sekarang masih giliran pemain " << listPlayer[playeridx-1].getName() << endl;
}

bool Command::continueToNextPlayer(List<Player>& listPlayer, int& playeridx){
    return false;
}

