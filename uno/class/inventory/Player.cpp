#include "Player.hpp"
#include "InventoryException.hpp"

using namespace std;

Player::Player() : InventoryHolder("Player"), playerID(0), name(""), haveWin(false) {};

Player::Player(int ID, string name): InventoryHolder("Player"), playerID(ID), name(name), haveWin(false) {};

bool Player::gethaveWin() {
    return this->haveWin;
}

void Player::sethaveWin(bool status) {
    this->haveWin = status;
}

int Player::getPlayerID() {
    return this->playerID;
}

string Player::getName() {
    return this->name;
}

void Player::setName(string name) {
    this->name = name;
}

vector<NumberCard>& Player::getPlayerCard() {
    return this->playerCards;
}

void Player::operator+(const NumberCard& card) {
    int i = 0;
    auto ptr = this->playerCards.begin(); 
    while (ptr != this->playerCards.end() && card > this->playerCards.at(i)) {
        i++;
        ptr++;
    }
    this->playerCards.insert(this->playerCards.begin() + i, card);
}

void Player::operator-(const NumberCard& card) {
    for (auto ptr = this->playerCards.begin(); ptr != this->playerCards.end(); ptr++) {
        if (ptr->getNumber() == card.getNumber()) {
            if (ptr->getNumber() <= 13 && ptr->getColor() == card.getColor()) {
                this->playerCards.erase(ptr);
                break;
            } else if (ptr->getNumber() > 13) {
                this->playerCards.erase(ptr);
                break;
            }
        }
    }
}

vector<NumberCard> Player::operator-(int vectorcard) {
    vector<NumberCard> temp;
    for (auto ptr = this->playerCards.begin(); ptr != this->playerCards.end(); ptr++) {
        if (ptr->getNumber() == vectorcard) {
            while (ptr->getNumber() == vectorcard && ptr != this->playerCards.end()) {
                temp.push_back(*ptr);
                ptr++;
            }
        }
    }
    return temp;
}

void Player::seeCard() {
    int i = 1;
    for (auto ptr = this->playerCards.begin(); ptr != this->playerCards.end(); ptr++) {
        cout << i << ". ";
        cout << *ptr << endl;
        i++;
    }
}

bool Player::look(int id) {
    for (auto ptr = this->playerCards.begin(); ptr != this->playerCards.end(); ptr++) {
        if (id == 13 && (ptr->getNumber() == 13 || ptr->getNumber() == 14)) {
            return true;
        } else if (id == 14 && ptr->getNumber() == 14) {
            return true;
        }
    }
    return false;
}

void Player::terminateThisRound() {
    if (this->playerCards.size() == 0) {
        this->haveWin = true;
        cout << "Player " << this->name << " menang" << endl;
    } else if (this->playerCards.size() == 1) {
        cout << "UNO!" << endl;
    }
}
