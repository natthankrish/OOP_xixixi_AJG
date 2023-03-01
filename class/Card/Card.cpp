#include "Card.hpp"
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