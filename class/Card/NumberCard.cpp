#include "NumberCard.hpp"

#include <string>
using namespace std;

NumberCard::NumberCard(int number, string color): number(number), color(color) {
}
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