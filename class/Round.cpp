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

void Round::startRound(List<Player>&listPlayer, int &prize, CardsBank& cardsbank) {
    initializeRound(listPlayer, cardsbank);
    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;

    processCurrentPlayer(listPlayer, prize);
    
    while(this->playerRemaining > 0) {
        this->playerRemaining--;
        nextPlayer(listPlayer);
        processCurrentPlayer(listPlayer, prize);
    }
}

void Round::initializeRound(List<Player>&listPlayer, CardsBank& cardsbank) {
    if (this->roundID == 1) {
        cout << "RONDE 1 DIMULAI. SAATNYA PEMBAGIAN KARTU" << endl;
        cardsbank.bagiKartu(listPlayer);
    } else if (this->roundID == 2) {
        cout << "RONDE 2 DIMULAI. SAATNYA PEMBAGIAN ABILITY" << endl;
       // cardsbank.bagiAbility();
    } else {
        cout << "RONDE " << this->roundID << " DIMULAI." << endl;
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
    string perintah;
    // this->command->execute(*this, prize);
    listPlayer[this->getIdxCurrentPlayer()-1].seeCard();
    
    bool nextPerson = false;
    while (!nextPerson) {
        // masukan perintah
        cout << "Masukkan Perintah: "; 
        cin >> perintah;

        // // Percabangan buat objek
        // if (perintah == "CHECKPRIZE") {
        //     this->command = new CheckPrize("ordinary", "checkprize", prize);
        // } else if (perintah == "HELP") {
        //     this->command = new Help("ordinary", "checkprize", prize);
        // } else if (perintah == "NEXT") {
        //     this->command = new Next("ordinary", "next", listPlayer);
        // } else if (perintah == "DOUBLE") {
        //     this->command = new Double("ordinary", "double", listPlayer);
        // } else if (perintah == "HALF") {
        //     this->command = new Half("ordinary", "half", listPlayer);
        // } else if (perintah == "QUADRUPLE") {
        //     this->command = new Half("ability", "quadruple", listPlayer);
        // } else if (perintah == "QUARTER") {
        //     this->command = new Half("ability", "quarter", listPlayer);
        // } else {
        //     this->command = new Command();
        //     cout << "Masukan salah! Ketik HELP untuk bantuan."; 
        // }

        command->execute(listPlayer, this.getIdxCurrentPlayer()-1, prize);
        nextPerson = true;
    }
}
