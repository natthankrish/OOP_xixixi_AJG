#include "NumberCard.hpp"
#include <iostream>
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

void NumberCard::setColor(int colid) {
    if (colid == 1) {
        this->color = "merah";
    } else if (colid == 2){
        this->color = "hijau";
    } else if (colid == 3){
        this->color = "biru";
    } else if (colid == 4){
        this->color = "kuning";
    } 
    
}

bool NumberCard::operator==(const NumberCard& other) {
    return (this->number == other.number && this->color == other.color);
}

bool NumberCard::operator!=(const NumberCard& other) {
    return (!(*this == other));
}

bool NumberCard::operator< (NumberCard& other) const{
    if (this->number < other.number) {
        return true;
    }
    return false;
}

bool NumberCard::operator> (NumberCard& other) const {
    if (this->number > other.number) {
        return true;
    }
    return false;
}

ostream& operator<< (ostream& output, NumberCard card) {
    if (card.number >= 0 && card.number <= 10) {
        output << card.number;
    } else if (card.number == 11) {
        output << "Reverse";
    } else if (card.number == 12) {
        output << "Skip";
    } else if (card.number == 13) {
        output << "+2";
    } else if (card.number == 14) {
        output << "+4";
    } else {
        output << "All colors";
    }

    output << " ";

    if (card.number != 14 && card.number != 15) {
        output << card.color;
    }

    return output;
}