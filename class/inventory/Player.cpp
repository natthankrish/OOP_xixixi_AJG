#include "Player.hpp"

Player::Player(int ID, string name, int point): InventoryHolder("Player"), playerID(ID), name(name), point(point) {

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