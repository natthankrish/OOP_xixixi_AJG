#include "NumberCard.hpp"

#include <string>
using namespace std;

NumberCard::NumberCard(): number(-1), Card(){
}

NumberCard::NumberCard(int number, string color): number(number), color(color), Card() {
}

int NumberCard::getNumber() const {
    return this->number;
}

void NumberCard::setNumber(int number) {
    this->number = number;
}

string NumberCard::getColor() const {
    return this->color;
}

void NumberCard::setColor(string color) {
    this->color = color;
}

bool NumberCard::operator==(const NumberCard& other) {
    return (this->number == other.number && this->color == other.color);
}

bool NumberCard::operator!=(const NumberCard& other) {
    return (!(*this == other));
}