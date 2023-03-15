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

void Round::startRound(List<Player>&listPlayer, int &prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, TableCard& tablecard, bool& ascending) {
    initializeRound(listPlayer, cardsbank, abilitycardsbank, tablecard);
    string player = "Player " + to_string(this->idxCurrentPlayer);
    displayPlayerTurn(player, listPlayer.getElement(this->idxCurrentPlayer-1).getName());
    // cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;

    processCurrentPlayer(listPlayer, prize, cardsbank, abilitycardsbank, tablecard, ascending);
    
    while(this->playerRemaining > 0) {
        this->playerRemaining--;
        nextPlayer(listPlayer, ascending);
        processCurrentPlayer(listPlayer, prize, cardsbank, abilitycardsbank, tablecard, ascending);
    }
}

void Round::initializeRound(List<Player>&listPlayer, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, TableCard& tablecard) {
    for(int i = 0; i < listPlayer.getNeff(); i++){
        listPlayer[i].sethavePlayed(false);
    }
    if (this->roundID == 1) {
        displayTitle("RONDE 1", "SAATNYA PEMBAGIAN KARTU");
        cardsbank.bagiKartu(listPlayer);
    } else if (this->roundID == 2) {
        displayTitle("RONDE 2", "SAATNYA PEMBAGIAN ABILITY");
        abilitycardsbank.bagiAbility(listPlayer);
        int idx = cardsbank.getElement().size() - 1;
        tablecard + cardsbank.getElementAt(idx);
        cardsbank - cardsbank.getElementAt(idx);
        // cout << cardsbank.getElement().size() <<endl;
    } else {
        string round = "RONDE " + to_string(this->roundID);
        displayTitle(round, "None");
        int idx = cardsbank.getElement().size() - 1;
        tablecard + cardsbank.getElementAt(idx);
        cardsbank - cardsbank.getElementAt(idx);
        // cout << cardsbank.getElement().size() <<endl;
    }
    cout << "--------------------------------------------------" << endl;
}

void Round::nextPlayer(List<Player>& listPlayer, bool& ascending) {
    if (ascending) {
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
    string player = "Player " + to_string(this->idxCurrentPlayer);
    displayPlayerTurn(player, listPlayer.getElement(this->idxCurrentPlayer-1).getName());

}

void Round::processCurrentPlayer(List<Player>& listPlayer, int &prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank, TableCard& tablecard, bool& ascending) {
    string perintah;
    // this->command->execute(*this, prize);
    
    bool nextPerson = false;
    while (!nextPerson) {
        // masukan perintah
        cout << "Masukkan Perintah: "; 
        cin >> perintah;
        perintah = capitalize(perintah);
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
        } else if (perintah == "CHECKTABLECARD") {
            this->command = new CheckTableCard("ordinary", "checktablecard");
        } else if (perintah == "CHANGECARD") {
            this->command = new ChangeCard("ordinary", "changenum");
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
    listPlayer[this->getIdxCurrentPlayer()-1].sethavePlayed(true);
}

string Round::capitalize(string command){
    for (int i = 0; i < command.length(); i++){
        command[i] = toupper(command[i]);
    }
    return command;
}

void Round::displayTitle(string title, string subtitle){
    string border = "==================================================" ;
    int whitespace = border.length() - title.length() - 4;
    int frontwhitespace = whitespace / 2;
    int backwhitespace = whitespace - frontwhitespace;
    cout << border << endl;
    cout << "==";
    for( int i = 0; i < frontwhitespace ; i++){
        cout << " ";
    }
    cout << title;
    for (int i = 0; i < backwhitespace; i++){
        cout << " ";
    }
    cout << "==" << endl;
    cout << border << endl;
    if (subtitle != "None"){
        int whitespace = border.length() - subtitle.length() - 4;
        int frontwhitespace = whitespace / 2;
        int backwhitespace = whitespace - frontwhitespace;
        cout << "==";
        for( int i = 0; i < frontwhitespace ; i++){
            cout << " ";
        }
        cout << subtitle;
        for (int i = 0; i < backwhitespace; i++){
            cout << " ";
        }
        cout << "==" << endl;
        cout << border << endl;
    }
}

void Round::displayPlayerTurn(string player, string name) {
    string border = "==================================================" ;
    int i;
    int whitespace = border.length() - player.length() - name.length() - 6;
    int fwhitespace = whitespace /2;
    int bwhitespace = whitespace - fwhitespace;
    int ffwhitespace = fwhitespace/2;
    int fbwhitespace = fwhitespace - ffwhitespace;
    int bfwhitespace = bwhitespace/2;
    int bbwhitespace = bwhitespace - bfwhitespace;
    cout << border << endl;
    cout << "==" ;
    for (i = 0; i < ffwhitespace; i++){
        cout << " ";
    }
    cout << player;
    for (i = 0; i < fbwhitespace; i++){
        cout << " ";
    }
    cout << "==";
    for (i = 0; i < bfwhitespace; i++){
        cout << " ";
    }
    cout << name;
    for (i = 0; i < bbwhitespace; i++){
        cout << " ";
    }
    cout << "==" << endl;
    cout << border << endl;
}


