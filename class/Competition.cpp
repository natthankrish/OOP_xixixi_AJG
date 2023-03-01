#include <iostream>
#include "Competition.hpp"
#include "Game.hpp"

using namespace std;

Competition::Competition() {
    cout << "INISIALISASI PLAYER DAN DECK" << endl;
}

void Competition::startCompetition() {
    cout << "MEMULAI PERMAINAN" << endl;
    this->currentGame = new Game(1);
}

