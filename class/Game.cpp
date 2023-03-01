#include "Game.hpp"
#include <iostream>

using namespace std;

Game::Game(int gameID) {
    this->gameID = gameID;
    cout << "PERMAIAN " << this->gameID << " dimulai" << endl;
    this->round = new Round(1, 2);
}
