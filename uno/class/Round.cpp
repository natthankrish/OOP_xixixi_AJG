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


    string player = "Player " + to_string(this->idxCurrentPlayer);
    displayPlayerTurn(player, listPlayer.getElement(this->idxCurrentPlayer-1).getName());
    // cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << " (" <<listPlayer.getElement(this->idxCurrentPlayer-1).getName() << ")" << endl;
    
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
    displayTitle("SAATNYA PEMBAGIAN KARTU", "None");
    // cout << "SAATNYA PEMBAGIAN KARTU" << endl;
    cardsbank.bagiKartu(listPlayer);
    // cout << "----------------------------------------------------------" << endl;
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
    string player = "Player " + to_string(this->idxCurrentPlayer);
    displayPlayerTurn(player, listPlayer.getElement(this->idxCurrentPlayer-1).getName());
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
        perintah = capitalize(perintah);
        // Percabangan buat objek
        if (perintah == "NEXT") {
            this->command = new Next("ordinary", "next");
        } else if (perintah == "THROW") {
            this->command = new Throw("ordinary", "throw");
        } else if (perintah == "CHECKTABLECARD") {
            this->command = new CheckTable("ordinary", "double");
        } else if (perintah == "MYCARD") {
            this->command = new MyCard("ordinary", "mycard");
        } else if (perintah == "PICK") {
            this->command = new Pick("ordinary", "pick");
        } else if (perintah == "HELP") {
            this->command = new Help("ordinary", "help");
        } else {
            this->command = new Command("none", "none");
        }
        this->command->execute(tablecard, listPlayer, this->idxCurrentPlayer, cardsbank, this->ascending, this->cardToPick);
        nextPerson = this->command->continueToNextPlayer(listPlayer, this->idxCurrentPlayer);
        //listPlayer[this->getIdxCurrentPlayer()-1].sethavePlayed(true);
    }
    listPlayer[this->idxCurrentPlayer-1].terminateThisRound();
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


