#include <iostream>
#include "Competition.hpp"
#include "Game.hpp"
#include "inventory/InventoryHolder.hpp"

using namespace std;

Competition::Competition() {
    int n;
    cout << "INISIALISASI PLAYER DAN DECK" << endl;
    cout << "Masukkan jumlah pemain (2-7 pemain): ";
    cin >> n;

    while (n > 7 || n < 2) {
        cout << "Masukkan salah! silahkan input jumlah pemain yang benar: ";
        cin >> n;
    }

    this->ListOfPlayer = new List<Player>(n);
    for (int i = 0; i < n; i++) {
        string playerName;
        cout << "Masukkan nama player " << i+1 << ": ";
        cin >> playerName;
        Player* player = new Player(1, playerName);
        ListOfPlayer->insertLast(*player);
    }
    
}

void Competition::startCompetition() {
    cout << "MEMULAI PERMAINAN" << endl;
    this->currentGame = new Game(1);
    int maxPoint = currentGame->startGame(*(this->ListOfPlayer));
}

