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

void Round::startRound(List<Player>& listPlayer, int &prize) {
    cout << "RONDE " << this->roundID << " dimulai" << endl;

    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;

    processCurrentPlayer(prize);
    cout << prize << endl;
    while(this->playerRemaining > 0) {
        this->playerRemaining--;
        nextPlayer(listPlayer);
        processCurrentPlayer(prize);
        cout << prize << endl;
    }
}

void Round::nextPlayer(List<Player>& listPlayer) {
    this->idxCurrentPlayer++;
    if (this->idxCurrentPlayer > 7) {
        this->idxCurrentPlayer = 1; 
    }
    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;
}

void Round::processCurrentPlayer(int &prize) {
    string command;
    cout << "Masukkan Perintah: "; 
    cin >> command;
    if (command == "NEXT") {
        cout << "Giliran dilanjut ke player selanjutnya" << endl;
    } else if (command == "DOUBLE") {
        cout << "Nama pemain melakukan DOUBLE, point hadiah naik dari" << prize << endl;
        prize *= 2; 
        cout << "ke" << prize << endl;
    } else if (command == "HALF") {
        if (prize != 1) {
            cout << "Nama pemain melakukan HALF, point hadiah turun dari" << prize << endl;
            prize *= 0.5; 
            cout << "ke" << prize << endl;
        } else {
            cout << "Gak jadi turun" << endl;
        }
    }
}