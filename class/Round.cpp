#include "Round.hpp"
#include <iostream>

using namespace std;

Round::Round(int roundID, int idxCurrentPlayer) {
    this->roundID = roundID;
    this->idxCurrentPlayer = idxCurrentPlayer;
    cout << "RONDE " << this->roundID << " dimulai" << endl;
    cout << "Sekarang Giliran Pemain " << this->idxCurrentPlayer << endl;
}