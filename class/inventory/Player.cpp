#include "Player.hpp"
#include "InventoryException.hpp"

Player::Player() : InventoryHolder("Player"), playerID(0), name(""), point(0) , havePlayedThisRound(false), abilityCardStatus(true) {};

Player::Player(int ID, string name, long long int point, bool status) : InventoryHolder("Player"), playerID(ID), name(name), point(point), havePlayedThisRound(false), abilityCardStatus(true) {};

Player& Player::operator=(const Player& p){
    this->playerID = p.playerID;
    this->name = p.name;
    this-> point = p.point;
    this->havePlayedThisRound = p.havePlayedThisRound;
    this->abilityCard = p.abilityCard;
    this->abilityCardStatus = p.abilityCardStatus;

    this->playerCards.first = p.playerCards.first;
    this->playerCards.second = p.playerCards.second;
    return *this;
}

bool Player::gethavePlayed() {
    return this->havePlayedThisRound;
}
void Player::sethavePlayed(bool status) {
    this->havePlayedThisRound = status;
}
void Player::updatePoint(long long int point) {
    this->point += point;
}
long long int Player::getPoint() {
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

AbilityCard Player::getAbilityCard(){
    return this->abilityCard;
}

void Player::setAbilityCard(AbilityCard abilityCard){
    this->abilityCard = abilityCard;
}

bool Player::getAbilityStatus() {
    return this->abilityCardStatus;
}

void Player::setAbilityStatus(bool val) {
    this->abilityCardStatus = val;
}

void Player::operator+(const NumberCard& card) {
    if (this->playerCards.first.getNumber() == -1) {
        this->playerCards.first = card;
    } else if (this->playerCards.second.getNumber() == -1) {
        this->playerCards.second = card;
    }
}

void Player::operator+(const AbilityCard& card) {
    this->abilityCard = card;
}

void Player::operator-(const NumberCard& card) {
    if (this->playerCards.second == card) {
        this->playerCards.second = NumberCard();
    } else if (this->playerCards.first == card) {
        this->playerCards.first = this->playerCards.second;
        this->playerCards.second = NumberCard();
    }
}

AbilityCard Player::operator-(const AbilityCard& card) {
    AbilityCard temp = card;
    this->abilityCard = AbilityCard();
    return temp;
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
    if (this->abilityCard != AbilityCard()) {
        cout << "Kartu Ability: " << this->abilityCard.getAbilityName() << " (";
        if (this->abilityCardStatus) {
            cout << "aktif";
        } else {
            cout << "dimatikan oleh Abilityless";
        }
        cout << ")" << endl;
    }
}

pair <NumberCard, NumberCard> Player::getPairOfCards() {
    return this->playerCards;
}
