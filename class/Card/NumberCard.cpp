#include "NumberCard.hpp"

#include <string>
using namespace std;

NumberCard::NumberCard(): number(-1), Card(){
}

NumberCard::NumberCard(int number, string color): number(number), color(color), Card() {
}

NumberCard& NumberCard::operator=(const NumberCard& nc){
    this->number = nc.number;
    this->color = nc.number;
    return *this;
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

int NumberCard::getColorWeight() const {
    if (this->color == "hijau") {
        return 0;
    } else if (this->color == "biru") {
        return 1;
    } else if (this->color == "kuning") {
        return 2;
    } else if (this->color == "merah") {
        return 3;
    } else {
        return -1;
    }
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