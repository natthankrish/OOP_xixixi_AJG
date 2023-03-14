#include <iostream>
#include "Competition.hpp"
#include "Game.hpp"
#include "inventory/InventoryHolder.hpp"

using namespace std;

Competition::Competition() {
    // cout << "INISIALISASI PLAYER DAN DECK" << endl;
    displayTitle("INISIALISASI PLAYER DAN DECK", "None");
    this->ListOfPlayer = new List<Player>(7);
    for (int i = 0;i < 7; i++) {
        string playerName;
        cout << "Masukkan nama player " << i+1 << ": " << endl;
        cout << "=> ";
        cin >> playerName;
        Player* player = new Player(1, playerName, 0, false);
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


