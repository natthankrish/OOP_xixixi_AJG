#include "Flush.hpp"
#include <cmath>
#include <iostream>
double Flush::getValue(vector<NumberCard> sortedCards, LookUpTable table){
    for (int i = sortedCards.size() - 1; i >= 0 + 4; i--) {
        bool isFlush = sortedCards[i - 1].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i - 2].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i - 3].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i - 4].getColor() == sortedCards[i].getColor();
        if (isFlush) {
            vector<NumberCard> bestCombo (sortedCards.begin() + i - 4, sortedCards.begin() + i + 1);
            double bestValue = 0;
            for (int j = 0; j < 5; j++) {
                bestValue += table.getValue(bestCombo[j]) * (pow(MAX_VALUE, -4 + j));
            }
            return MAX_VALUE*5 + bestValue;
        }
    }
    return 0;

}
vector<NumberCard> Flush::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    for (int i = sortedCards.size() - 1; i >= 0 + 4; i--) {
        bool isFlush = sortedCards[i - 1].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i - 2].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i - 3].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i - 4].getColor() == sortedCards[i].getColor();
        if (isFlush) {

            vector<NumberCard> bestCombo (sortedCards.begin() + i - 4, sortedCards.begin() + i + 1);
            return bestCombo;
        }
    }
}