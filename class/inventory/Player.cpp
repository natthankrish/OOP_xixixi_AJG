#include "Player.hpp"
#include "InventoryException.hpp"

Player::Player(): InventoryHolder("Player"), playerID(0), name(""), point(0) , havePlayedThisRound(false) {}

Player::Player(int ID, string name, int point, bool status): InventoryHolder("Player"), playerID(ID), name(name), point(point), havePlayedThisRound(false) {

}

bool Player::gethavePlayed() {
    return this->havePlayedThisRound;
}
bool Player::sethavePlayed(bool status) {
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
// void Player::setPlayerCards() {

// }
// void Player::searchBestDeckCards() {

// }

void Player::operator+(const NumberCard& card) {
    if (this->playerCards.first != NumberCard() && this->playerCards.second != NumberCard()) {
        throw PlayerCardFullException();
    }

    if (this->playerCards.first == NumberCard()) {
        this->playerCards.first = card;
    } else {
        this->playerCards.second = card;
    }
}

void Player::operator-(const NumberCard&) {
    if (this->playerCards.first == NumberCard() && this->playerCards.second == NumberCard()) {
        throw PlayerCardEmptyException();
    }

    if (this->playerCards.second != NumberCard()) {
        this->playerCards.second = NumberCard();
    } else {
        this->playerCards.first = NumberCard();
    }
}