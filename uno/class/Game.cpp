#include "Game.hpp"
#include <iostream>

using namespace std;


Game::Game(int gameID) {
    this->gameID = gameID;
}

int Game::startGame(List<Player>& listPlayer) {
    cout << "PERMAIAN UNO dimulai" << endl;
    this->round = new Round(1, 1);
    round->startRound(listPlayer, this->cardsBank, this->tablecard);
    
    cout << "Peringkat: " << endl; {
        for (int i = 0; i < listPlayer.getNeff(); i++) {
            cout << i+1 << ". " << listPlayer[i].getName() << endl;
        }
    }
    cout << "PERMAIAN SELESAI" << endl;
    return 0;
}

CardsBank Game::getCardsBank() {
    return this->cardsBank;
}
