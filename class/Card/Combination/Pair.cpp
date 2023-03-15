#include "Pair.hpp"
#include <cmath>

double Pair::getValue(vector<NumberCard> sortedCards, LookUpTable table){
     for (int i = sortedCards.size() - 1; i >= 0 + 1; i--) {
        bool isPair = sortedCards[i - 1].getNumber() == sortedCards[i].getNumber();
        if (isPair) {
            vector<NumberCard> bestCombo = vector<NumberCard> (sortedCards.begin() + i - 1, sortedCards.begin() + i + 1);
            double bestValue = 0;
            for (int j = 0; j < 2; j++) {
                bestValue += table.getValue(bestCombo[j]) * (pow(MAX_VALUE, -2 + j));
            }
            return MAX_VALUE + bestValue;
        }

    }
    return 0;
}
vector<NumberCard> Pair::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
     for (int i = sortedCards.size() - 1; i >= 0 + 1; i--) {
        bool isPair = sortedCards[i - 1].getNumber() == sortedCards[i].getNumber();
        if (isPair) {
            vector<NumberCard> bestCombo = vector<NumberCard> (sortedCards.begin() + i - 1, sortedCards.begin() + i + 1);
            return bestCombo;
        }

    }
    return vector<NumberCard>();
}