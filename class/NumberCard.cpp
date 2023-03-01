#include "NumberCard.hpp"

#include <string>
using namespace std;

int NumberCard::getNumber(){
    return this->number;
}

void NumberCard::setNumber(int number){
    this->number = number;
}

string NumberCard::getColor(){
    return this->color;
}

void NumberCard::setColor(string color){
    this->color = color;
}