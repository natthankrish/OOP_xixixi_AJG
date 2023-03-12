#include "Round.hpp"
#include <iostream>

using namespace std;

Round::Round(int roundID, int idxCurrentPlayer) {
    this->roundID = roundID;
    this->idxCurrentPlayer = idxCurrentPlayer;
    this->playerRemaining = 6;
}

int Round::getRoundID() {
    return this->roundID;
}

int Round::getIdxCurrentPlayer(){
    return this->idxCurrentPlayer;
}

void Round::startRound(List<Player>& listPlayer, int &prize) {
    cout << "RONDE " << this->roundID << " dimulai" << endl;

    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;

    processCurrentPlayer(listPlayer, prize);
    while(this->playerRemaining > 0) {
        this->playerRemaining--;
        nextPlayer(listPlayer);
        processCurrentPlayer(listPlayer, prize);
    }
}

void Round::nextPlayer(List<Player>& listPlayer) {
    this->idxCurrentPlayer++;
    if (this->idxCurrentPlayer > 7) {
        this->idxCurrentPlayer = 1; 
    }
    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;
}

void Round::processCurrentPlayer(List<Player>& listPlayer, int &prize) {
    string command;
    cout << "Masukkan Perintah: "; 
    cin >> command;

    bool abilityvalid = false;
    while (!(command == "HALF" || command == "DOUBLE" || command == "NEXT" || abilityvalid)) {
        if (command == "CHECKPRIZE") {
           this->command = new CheckPrize("ordinary", "checkprize", prize);
        } else if (command == "HELP") {
           this->command = new Help("ordinary", "checkprize", prize);
        } else if (command == "QUARTER") {
            abilityvalid = true;
            continue;
        } else if (command == "QUADRUPLE") {
            abilityvalid = true;
            continue;
        } else {
            cout << "Masukan salah! Ketik HELP untuk bantuan. "; 
        }
        cout << "Masukkan Perintah: "; 
        cin >> command;
    }

    if (command == "NEXT") {
        this->command = new Next("ordinary", "next", listPlayer);
    } else if (command == "DOUBLE") {
        this->command = new Double("ordinary", "double", listPlayer);
    } else if (command == "HALF") {
        this->command = new Half("ordinary", "half", listPlayer);
    } else if (command == "QUADRUPLE") {
        this->command = new Half("ability", "quadruple", listPlayer);
    } else if (command == "QUARTER") {
        this->command = new Half("ability", "quarter", listPlayer);
    } 

    this->command->execute(*this, prize);
}
