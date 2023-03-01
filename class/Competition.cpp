#include <iostream>
#include "Competition.hpp"
#include "Game.hpp"
#include "inventory/InventoryHolder.hpp"

using namespace std;

Competition::Competition() {
    cout << "INISIALISASI PLAYER DAN DECK" << endl;
    this->ListOfPlayer = new List<Player>(7);
    for (int i = 0;i < 7; i++) {
        string playerName;
        cout << "Masukkan nama player " << i+1 << ": ";
        cin >> playerName;
        Player* player = new Player(1, playerName, 0, false);
        ListOfPlayer->insertLast(*player);
    }
    
}

void Competition::startCompetition() {
    cout << "MEMULAI PERMAINAN" << endl;
    this->currentGame = new Game(1);
    int maxPoint = currentGame->startGame(*(this->ListOfPlayer));
}

