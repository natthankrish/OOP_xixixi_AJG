#include "Player.hpp"

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
// void Player::searchBestDeckCards(Card*) {

// }