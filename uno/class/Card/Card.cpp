#include "Card.hpp"
#include <iostream>

using namespace std;

Card::Card() {
    this->value = -1;
    this->cardType = "none";
}

Card::Card(string name, int value) {
    this->value = value;
    this->cardType = name;
}

void Card::setCardType(string cardType){
    this->cardType = cardType;
}

string Card::getCardType() const{
    return this->cardType;
}

void Card::setValue(int value){
    this->value = value;
}

int Card::getValue() const{
    return this->value;
}   

bool Card::operator< (const Card&) {
    return false;
}