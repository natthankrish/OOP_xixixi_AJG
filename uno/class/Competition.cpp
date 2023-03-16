#include <iostream>
#include "Competition.hpp"
#include "Game.hpp"
#include "inventory/InventoryHolder.hpp"

using namespace std;

Competition::Competition() {
    int n;
    displayTitle("INISIALISASI PLAYER DAN DECK", "None");
    cout << "Masukkan jumlah pemain (2-7 pemain): ";
    cin >> n;

    while (n > 7 || n < 2) {
        cout << "Masukkan salah! silahkan input jumlah pemain yang benar: ";
        cin >> n;
    }

    this->ListOfPlayer = new List<Player>(n);
    for (int i = 0; i < n; i++) {
        string playerName;
        cout << "Masukkan nama player " << i+1 << ": " << endl;
        cout << "=> ";
        cin >> playerName;
        Player* player = new Player(1, playerName);
        ListOfPlayer->insertLast(*player);
    }
    
}

void Competition::startCompetition() {
    // cout << "MEMULAI PERMAINAN" << endl;
    displayTitle("MEMULAI PERMAINAN", "None");
    this->currentGame = new Game(1);
    int maxPoint = currentGame->startGame(*(this->ListOfPlayer));
}


void Competition::displayTitle(string title, string subtitle){
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
