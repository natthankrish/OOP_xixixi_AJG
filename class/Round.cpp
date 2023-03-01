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

void Round::startRound(List<Player>& listPlayer) {
    cout << "RONDE " << this->roundID << " dimulai" << endl;

    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;

    processCurrentPlayer();
    while(this->playerRemaining > 0) {
        this->playerRemaining--;
        nextPlayer(listPlayer);
        processCurrentPlayer();
    }
}

void Round::nextPlayer(List<Player>& listPlayer) {
    this->idxCurrentPlayer++;
    if (this->idxCurrentPlayer > 7) {
        this->idxCurrentPlayer = 1; 
    }
    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;
}

void Round::processCurrentPlayer() {
    string command;
    cout << "Masukkan Perintah: "; 
    cin >> command;
    // VALIDASI PERINTAH
}