#include "Round.hpp"
#include <iostream>

using namespace std;

Round::Round(int roundID, int idxCurrentPlayer) {
    this->roundID = roundID;
    this->idxCurrentPlayer = idxCurrentPlayer;
    this->playerRemaining = 6;
    this->ascending = true;
}

int Round::getRoundID() {
    return this->roundID;
}

int Round::getIdxCurrentPlayer(){
    return this->idxCurrentPlayer;
}

void Round::startRound(List<Player>&listPlayer, int &prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, TableCard& tablecard) {
    initializeRound(listPlayer, cardsbank, abilitycardsbank);
    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;

    processCurrentPlayer(listPlayer, prize, cardsbank, abilitycardsbank, tablecard);
    
    while(this->playerRemaining > 0) {
        this->playerRemaining--;
        nextPlayer(listPlayer);
        processCurrentPlayer(listPlayer, prize, cardsbank, abilitycardsbank, tablecard);
    }
}

void Round::initializeRound(List<Player>&listPlayer, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    if (this->roundID == 1) {
        cout << "RONDE 1 DIMULAI. SAATNYA PEMBAGIAN KARTU" << endl;
        cardsbank.bagiKartu(listPlayer);
    } else if (this->roundID == 2) {
        cout << "RONDE 2 DIMULAI. SAATNYA PEMBAGIAN ABILITY" << endl;
        abilitycardsbank.bagiAbility(listPlayer);
    } else {
        cout << "RONDE " << this->roundID << " DIMULAI." << endl;
    }
    cout << "----------------------------------------------------------" << endl;
}

void Round::nextPlayer(List<Player>& listPlayer) {
    if (this->ascending) {
        this->idxCurrentPlayer++;
        if (this->idxCurrentPlayer > 7) {
            this->idxCurrentPlayer = 1; 
        }
        while (listPlayer[this->idxCurrentPlayer-1].gethavePlayed()) {
            this->idxCurrentPlayer++;
            if (this->idxCurrentPlayer > 7) {
                this->idxCurrentPlayer = 1; 
            }
        }
    } else {
        this->idxCurrentPlayer--;
        if (this->idxCurrentPlayer < 1) {
            this->idxCurrentPlayer = 7; 
        }
        while (listPlayer[this->idxCurrentPlayer-1].gethavePlayed()) {
            this->idxCurrentPlayer--;
            if (this->idxCurrentPlayer < 1) {
                this->idxCurrentPlayer = 7; 
            }
        }
    }
    cout << "----------------------------------------------------------" << endl;
    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" << listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;

}

void Round::processCurrentPlayer(List<Player>& listPlayer, int &prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, TableCard& tablecard) {
    string perintah;
    // this->command->execute(*this, prize);
    
    bool nextPerson = false;
    while (!nextPerson) {
        // masukan perintah
        cout << "Masukkan Perintah: "; 
        cin >> perintah;
        // Percabangan buat objek
        if (perintah == "CHECKPRIZE") {
            this->command = new CheckPrize("ordinary", "checkprize");
        } else if (perintah == "HELP") {
            this->command = new Help("ordinary", "help");
        } else if (perintah == "NEXT") {
            this->command = new Next("ordinary", "next");
        } else if (perintah == "DOUBLE") {
            this->command = new Double("ordinary", "double");
        } else if (perintah == "HALF") {
            this->command = new Half("ordinary", "half");
        } else if (perintah == "MYCARD") {
            this->command = new MyCard("ordinary", "mycard");
        } else if (perintah == "CHANGEPLAYERCARD") {
            this->command = new ChangePlayerCard("ordinary", "changenum");
        } else if (perintah == "QUADRUPLE") {
            this->command = new Quadruple("ability", "quadruple");
        } else if (perintah == "QUARTER") {
            this->command = new Quarter("ability", "quarter");
        } else if (perintah == "REROLL") {
            this->command = new Reroll("ability", "reroll");
        } else if (perintah == "SWAP") {
            this->command = new Swap("ability", "swap");
        } else if (perintah == "SWITCH") {
            this->command = new Switch("ability", "switch");
        } else if (perintah == "REVERSE") {
            this->command = new Reverse("ability", "reverse");
        } else if (perintah == "ABILITYLESS") {
            this->command = new Abilityless("ability", "abilityless");
        } else {
            this->command = new Command("none", "none");
        }

        this->command->execute(tablecard, listPlayer, this->getIdxCurrentPlayer(), prize, cardsbank, abilitycardsbank, ascending);
        nextPerson = this->command->continueToNextPlayer(listPlayer, this->getIdxCurrentPlayer(), abilitycardsbank);
        //listPlayer[this->getIdxCurrentPlayer()-1].sethavePlayed(true);
    }
}
