#include <map>
#include <vector>
#include "LookupTable.hpp"


LookUpTable::LookUpTable() {
    for (int i = 0; i < COLORS.size(); i++) {
        this->colorValue[COLORS[i]] = i;
        for (int j = 0; j < 13; j++) {
           this->cardValue[NumberCard(i + 1, COLORS[i])] =  0.1*j + i*0.03;
        }
    }
}

double LookUpTable::getValue(std::string color) {
    return this->colorValue[color];
}

double LookUpTable::getValue(NumberCard card) {
    return this->cardValue[card];
}

