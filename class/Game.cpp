#include "Game.hpp"
#include <iostream>
#include <time.h>

using namespace std;


Game::Game(int gameID) {
    this->prize = 64;
    this->maxPlayerPoint = 0;
    this->gameID = gameID;
    string color;
    vector<NumberCard> temp;
    for (int j = 0; j < 4; j++) {
        if (j == 0) {
            color = "merah";
        } else if (j == 1) {
            color = "kuning";
        } else if (j == 2) {
            color = "hijau";
        } else {
            color = "biru";
        }
        for (int i = 1; i < 14; i ++) {
            temp.push_back(NumberCard(i, color));
        }
    }

    //shuffling cards 
    srand(time(NULL));
    while (temp.size() > 0) {
        int idx = rand() % temp.size();
        this->CardsBank.push_back(temp[idx]);
        temp.erase(temp.begin() + idx);
    }
}

int Game::startGame(List<Player>& listPlayer) {
    cout << "PERMAIAN " << this->gameID << " dimulai" << endl;
    this->round = new Round(1, 1);
    round->startRound(listPlayer, this->prize);
    while (this->round->getRoundID() < 6) {
        NextRound();
        round->startRound(listPlayer, this->prize);
    }
    cout << "PERMAIAN SELESAI" << endl;
    return 0;
}
    
void Game::NextRound() {
    int roundEnded = round->getRoundID();
    delete this->round;
    this->round = new Round(roundEnded+1, roundEnded+1);
}

NumberCard Game::getCardBankAt(int i) {
    return this->CardsBank[i];
}

vector<NumberCard> Game::getCardBank() {
    return this->CardsBank;
}
