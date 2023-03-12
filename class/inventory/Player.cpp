#include "Player.hpp"
#include "InventoryException.hpp"

Player::Player() : InventoryHolder("Player"), playerID(0), name(""), point(0) , havePlayedThisRound(false) {};

Player::Player(int ID, string name, int point, bool status): InventoryHolder("Player"), playerID(ID), name(name), point(point), havePlayedThisRound(false) {};

bool Player::gethavePlayed() {
    return this->havePlayedThisRound;
}
void Player::sethavePlayed(bool status) {
    this->havePlayedThisRound = status;
}
void Player::updatePoint(int point) {
    this->point += point;
}
int Player::getPoint() {
    return this->point;
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
// void Player::searchBestDeckCards() {

// }

void Player::operator+(const NumberCard& card) {
    if (this->playerCards.first.getNumber() == -1) {
        this->playerCards.first = card;
    } else if (this->playerCards.second.getNumber() == -1) {
        this->playerCards.second = card;
    }
}

void Player::operator-(const NumberCard& card) {
    if (this->playerCards.first == NumberCard() && this->playerCards.second == NumberCard()) {
        this->playerCards.first = card;
    } else if (this->playerCards.second == NumberCard()) {
        this->playerCards.first = card;
    }
}

NumberCard Player::operator--() {
    NumberCard temp = this->playerCards.first;
    this->playerCards.first = this->playerCards.second;
    if (playerCards.second == NumberCard()) {
        this->playerCards.first = NumberCard();
    } else {
        this->playerCards.second = NumberCard();
    }
    return temp;
}

void Player::seeCard() {
    cout << "Kartu 1: " << this->playerCards.first.getNumber() << " " << this->playerCards.first.getColor() << endl;
    cout << "Kartu 2: " << this->playerCards.second.getNumber() << " " << this->playerCards.second.getColor() << endl;
}