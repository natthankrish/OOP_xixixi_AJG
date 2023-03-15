#include "Round.hpp"
#include <iostream>

using namespace std;

Round::Round(int roundID, int idxCurrentPlayer) {
    this->roundID = roundID;
    this->idxCurrentPlayer = idxCurrentPlayer;
    this->ascending = true;
    this->cardToPick = 0;
}

int Round::getRoundID() {
    return this->roundID;
}

int Round::getIdxCurrentPlayer(){
    return this->idxCurrentPlayer;
}

void Round::startRound(List<Player>& listPlayer, CardsBank& cardsbank, TableCard& tablecard) {
    initializeRound(listPlayer, cardsbank);


    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;
    
    NumberCard pick = cardsbank.operator--();
    while (pick.getNumber() > 10) {
        cardsbank + pick;
        pick = cardsbank.operator--();
    }

    tablecard + pick;
    
    processCurrentPlayer(listPlayer, cardsbank, tablecard);

    int count = 0;
    for (int i = 0; i < listPlayer.getNeff(); i++) {
        if (!listPlayer[i].gethaveWin()) {
            count++;
        }
    }
    while(count > 1) {
        nextPlayer(listPlayer);
        processCurrentPlayer(listPlayer, cardsbank, tablecard);
        count = 0;
        for (int i = 0; i < listPlayer.getNeff(); i++) {
            if (!listPlayer[i].gethaveWin()) {
                count++;
            }
        }
    }

}

void Round::initializeRound(List<Player>&listPlayer, CardsBank& cardsbank) {
    cout << "SAATNYA PEMBAGIAN KARTU" << endl;
    cardsbank.bagiKartu(listPlayer);
    cout << "----------------------------------------------------------" << endl;
}

void Round::nextPlayer(List<Player>& listPlayer) {
    int count = 0;
    for (int i = 0; i < listPlayer.getNeff(); i++) {
        if (!listPlayer[i].gethaveWin()) {
            count++;
        }
    }
    if (this->ascending) {
        this->idxCurrentPlayer++;
        if (this->idxCurrentPlayer > count) {
            this->idxCurrentPlayer -= count;  
        }
        while (listPlayer[this->idxCurrentPlayer-1].gethaveWin()) {
            this->idxCurrentPlayer++;
            if (this->idxCurrentPlayer > count) {
                this->idxCurrentPlayer -= count; 
            }
        }
    } else {
        this->idxCurrentPlayer--;
        if (this->idxCurrentPlayer < 1) {
            this->idxCurrentPlayer += count; 
        }
        while (listPlayer[this->idxCurrentPlayer-1].gethaveWin()) {
            this->idxCurrentPlayer--;
            if (this->idxCurrentPlayer < 1) {
                this->idxCurrentPlayer += count; 
            }
        }
    }
    cout << "----------------------------------------------------------" << endl;
    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;
}

void Round::getCardToPick(List<Player>& listPlayer, CardsBank& cardsbank, TableCard& tablecard) {
    if (this->cardToPick > 0) {
        if (!(listPlayer[this->idxCurrentPlayer-1].look(tablecard.Top().getNumber()))) {
            cout << "Wahh kamu tidak mempunyai kartu untuk melawan. Mengambil " << this->cardToPick << " kartu" << endl;
            for (int i = 0; i < this->cardToPick; i++) {
                listPlayer[this->idxCurrentPlayer-1] + cardsbank.operator--();
            }
            this->cardToPick = 0;
            nextPlayer(listPlayer);
        }
    }
}

void Round::processCurrentPlayer(List<Player>& listPlayer, CardsBank& cardsbank, TableCard& tablecard) {
    string perintah;
    // this->command->execute(*this, prize);
    getCardToPick(listPlayer, cardsbank, tablecard);
    bool nextPerson = false;
    while (!nextPerson) {
        // masukan perintah
        cout << "Masukkan Perintah: "; 
        cin >> perintah;
        // Percabangan buat objek
        if (perintah == "NEXT") {
            this->command = new Next("ordinary", "next");
        } else if (perintah == "THROW") {
            this->command = new Throw("ordinary", "throw");
        } else if (perintah == "CHECKTABLE") {
            this->command = new CheckTable("ordinary", "double");
        } else if (perintah == "MYCARD") {
            this->command = new MyCard("ordinary", "mycard");
        } else if (perintah == "PICK") {
            this->command = new Pick("ordinary", "pick");
        } else {
            this->command = new Command("none", "none");
        }
        this->command->execute(tablecard, listPlayer, this->idxCurrentPlayer, cardsbank, this->ascending, this->cardToPick);
        nextPerson = this->command->continueToNextPlayer(listPlayer, this->idxCurrentPlayer);
        //listPlayer[this->getIdxCurrentPlayer()-1].sethavePlayed(true);
    }
    listPlayer[this->idxCurrentPlayer-1].terminateThisRound();
}
