#include "ThreeOfKind.hpp"
#include <cmath>

double ThreeOfKind::getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    double bestValue = 0;
    
    for (int i = 0; i < sortedCards.size() - 3; i++) {
        bool isThreeOfKind = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i + 2].getNumber() == sortedCards[i].getNumber();
        if (!isThreeOfKind) 
            continue;

        double currentValue = 0;
        for (int i = 0; i < 3; i++) {
            currentValue += table.getValue(sortedCards[i]) / (pow(MAX_VALUE, -2 + i));
        }
        currentValue += table.getValue(sortedCards[3]) / MAX_VALUE;

        bestValue = (currentValue > bestValue) ? currentValue : bestValue;

    }

    return bestValue;
}


vector<NumberCard> ThreeOfKind::getCombo(vector<NumberCard> sortedCards, LookUpTable table) {
    double bestValue = 0;
    vector<NumberCard> bestCombo;

    for (int i = 0; i < sortedCards.size() - 3; i++) {
        bool isThreeOfKind = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber() &&
                             sortedCards[i + 2].getNumber() == sortedCards[i].getNumber();
        if (!isThreeOfKind)
            continue;

        double currentValue = 0;
        for (int j = 0; j < 3; j++) {
            currentValue += table.getValue(sortedCards[j]) / (pow(MAX_VALUE, -2 + j));
        }
        for (int j = 3; j < 5; j++) {
            currentValue += table.getValue(sortedCards[j]) / (pow(MAX_VALUE, -2));
        }

        if (currentValue > bestValue) {
            bestValue = currentValue;
            auto first = sortedCards.begin() + i;
            auto end = sortedCards.begin() + i + 3;
            bestCombo = vector<NumberCard>(first, end);
            for (int j = 3; j < 5; j++) {
                bestCombo.push_back(sortedCards[j]);
            }
        }
    }

    return bestCombo;
}

