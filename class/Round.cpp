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
            cout << "Hadiah Game pada saat ini adalah " << prize << endl;
            cout << "Sekarang masih giliran " << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << endl;
        } else if (command == "HELP") {
            cout << "PUSAT BANTUAN" << endl;
            cout << "---------------------------------------" << endl;
            cout << "Masih under construction" << endl;
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
        cout << "Giliran dilanjut ke player selanjutnya." << endl;
    } else if (command == "DOUBLE") {
        cout << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << " melakukan DOUBLE! Point hadiah naik dari " << prize;
        prize *= 2; 
        cout << " menjadi " << prize << endl;
    } else if (command == "HALF") {
        if (prize != 1) {
            cout << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << " melakukan HALF! Point hadiah turun dari " << prize;
            prize *= 0.5; 
            cout << " menjadi " << prize << endl;
        } else {
            cout << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << " melakukan HALF! Sayangnya hadiah sudah mencapai angka 1." << endl;
            cout << "Pengurangan poin dibatalkan. Giliran pemain selanjutnya." << endl;
        }
    } else if (command == "QUADRUPLE") {
        cout << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << " melakukan QUADRUPLE! Point hadiah naik dari " << prize;
        prize *= 4; 
        cout << " menjadi " << prize << endl;
    } else if (command == "QUARTER") {
        if (prize >= 4) {
            cout << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << " melakukan QUARTER! Point hadiah turun dari " << prize;
            prize *= 0.25; 
            cout << " menjadi " << prize << endl;
        } else if (prize == 2) {
            cout << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << " melakukan QUARTER! Sayangnya point hadiah hanya turun dari " << prize;
            prize *= 0.5; 
            cout << " menjadi " << prize << endl;
        } else {
            cout << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << " melakukan QUARTER! Sayangnya hadiah sudah mencapai angka 1." << endl;
            cout << "Pengurangan poin dibatalkan. Giliran pemain selanjutnya." << endl;
        }
    } 
}