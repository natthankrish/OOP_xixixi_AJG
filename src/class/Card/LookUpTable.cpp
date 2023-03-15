#include <map>
#include <vector>
#include "LookUpTable.hpp"


LookUpTable::LookUpTable() {
    for (int i = 0; i < COLORS.size(); i++) {
        this->colorValue[COLORS[i]] = i;
        for (int j = 0; j < 13; j++) {
            string key = to_string(j+1) + COLORS[i];
            this->cardValue[key] =  0.1*j + i*0.03;
        }
    }
}

double LookUpTable::getValue(std::string color) {
    return this->colorValue[color];
}

double LookUpTable::getValue(NumberCard card) {
    string key = to_string(card.getNumber()) + card.getColor();
    return this->cardValue[key];
}

