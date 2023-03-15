#include "ThreeOfKind.hpp"
#include <cmath>

double ThreeOfKind::getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    if (sortedCards.size() >= 3) {
        for (int i = sortedCards.size() - 1; i >= 0 + 2; i--) {
            bool isTriple = sortedCards[i - 1].getNumber() == sortedCards[i].getNumber() &&
                                sortedCards[i - 2].getNumber() == sortedCards[i].getNumber();
            if (isTriple) {
                vector<NumberCard> bestTriple = vector<NumberCard> (sortedCards.begin() + i - 2, sortedCards.begin() + i + 1);
                double bestValue = 0;
                for (int j = 0; j < 3; j++) {
                    bestValue += table.getValue(bestTriple[j]) * (pow(MAX_VALUE, -3 + j));
                }
                return (MAX_VALUE + bestValue) * 30;
            }

        }
    }
    return 0;
}


vector<NumberCard> ThreeOfKind::getCombo(vector<NumberCard> sortedCards, LookUpTable table) {
    for (int i = sortedCards.size() - 1; i >= 0 + 2; i--) {
        bool isTriple = sortedCards[i - 1].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i - 2].getNumber() == sortedCards[i].getNumber();
        if (isTriple) {
            vector<NumberCard> bestTriple = vector<NumberCard> (sortedCards.begin() + i - 2, sortedCards.begin() + i + 1);
            return bestTriple;
        }
    }
    return vector<NumberCard>();
}

