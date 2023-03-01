#include "Card.hpp"

Card& Card::operator=(const Card&){
    this->cardType = cardType;
    this->value = value;

    return *this;
}


void Card::setCardType(string cardType){
    this->cardType = cardType;
}


string Card::getCardType(){
    return this->cardType;
}


void Card::setValue(int value){
    this->value = value;
}


int Card::getValue(){
    return this->value;
}   