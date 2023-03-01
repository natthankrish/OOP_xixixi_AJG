#include "Game.hpp"
#include <iostream>

using namespace std;

Game::Game(int gameID) {
    this->prize = 0;
    this->maxPlayerPoint = 0;
    this->gameID = gameID;
}

int Game::startGame(List<Player>& listPlayer) {
    cout << "PERMAIAN " << this->gameID << " dimulai" << endl;
    this->round = new Round(1, 1);
    round->startRound(listPlayer);
    while (this->round->getRoundID() < 6) {
        NextRound();
        round->startRound(listPlayer);
    }
    cout << "PERMAIAN SELESAI" << endl;
    return 0;
}
    
void Game::NextRound() {
    int roundEnded = round->getRoundID();
    delete this->round;
    this->round = new Round(roundEnded+1, roundEnded+1);
}
