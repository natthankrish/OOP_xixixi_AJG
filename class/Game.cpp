#include "Game.hpp"
#include <iostream>

using namespace std;


Game::Game(int gameID) {
    this->prize = 64;
    this->maxPlayerPoint = 0;
    this->gameID = gameID;
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

AbilityCardsBank Game::getAbilityCardsBank() {
    return this->abilityCardsBank;
}
CardsBank Game::getCardsBank() {
    return this->cardsBank;
}
