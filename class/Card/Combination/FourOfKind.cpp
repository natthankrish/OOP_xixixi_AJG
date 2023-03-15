#include "FourOfKind.hpp"
#include <cmath>
#include <iostream>

double FourOfKind::getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    for (int i = sortedCards.size() - 1; i >= 0 + 3; i--) {
        bool isFourOfKind = sortedCards[i - 1].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i - 2].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i - 3].getNumber() == sortedCards[i].getNumber();
        if (isFourOfKind) {
            vector<NumberCard> bestCombo = vector<NumberCard> (sortedCards.begin() + i - 3, sortedCards.begin() + i + 1);
            double bestValue = 0;
            for (int j = 0; j < 4; j++) {
                bestValue += table.getValue(sortedCards[j]) * (pow(MAX_VALUE, -4 + j));
            }
            return MAX_VALUE*6 + bestValue;
        }

    }
    return 0;
}

vector<NumberCard> FourOfKind::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    for (int i = sortedCards.size() - 1; i >= 0 + 3; i--) {
        bool isFourOfKind = sortedCards[i - 1].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i - 2].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i - 3].getNumber() == sortedCards[i].getNumber();
        if (isFourOfKind) {
            vector<NumberCard> bestCombo = vector<NumberCard> (sortedCards.begin() + i - 3, sortedCards.begin() + i + 1);
            return bestCombo;
        }

    }
    return vector<NumberCard> ();
}
