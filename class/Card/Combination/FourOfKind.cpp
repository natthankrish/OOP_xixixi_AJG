#include "FourOfKind.hpp"
#include <cmath>

double FourOfKind::getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    double bestValue = 0;
    
    for (int i = 0; i < sortedCards.size() - 4; i++) {
        bool isFourOfKind = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i + 2].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i + 3].getNumber() == sortedCards[i].getNumber();
        if (!isFourOfKind) 
            continue;

        double currentValue = 0;
        for (int j = 0; j < 4; j++) {
            currentValue += table.getValue(sortedCards[j]) / (pow(MAX_VALUE, -3 + j));
        }

        bestValue = (currentValue > bestValue) ? currentValue : bestValue;

    }

    return bestValue;
}

vector<NumberCard> FourOfKind::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue = 0;
    vector<NumberCard> bestCombo;
    
    for (int i = 0; i < sortedCards.size() - 4; i++) {
        bool isFourOfKind = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i + 2].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i + 3].getNumber() == sortedCards[i].getNumber();
        if (!isFourOfKind) 
            continue;

        double currentValue = 0;
        for (int j = 0; j < 4; j++) {
            currentValue += table.getValue(sortedCards[j]) / (pow(MAX_VALUE, -3 + j));
        }

        if(currentValue > bestValue) {
            bestValue = currentValue;
            auto first = sortedCards.begin() + i;
            auto end = sortedCards.begin() + i + 4;
            bestCombo = vector<NumberCard> (first, end);
            // sebenernya bisa langsung return
        }

    }

    return bestCombo;
}
