#include "Straight.hpp"
#include <cmath>


double Straight::getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    double bestValue = 0;

    for (int i = 0; i < sortedCards.size() - 5; i++) {
        bool isStraight = sortedCards[i + 1].getNumber() - sortedCards[i].getNumber() == 1 &&
                            sortedCards[i + 2].getNumber() - sortedCards[i].getNumber() == 2 &&
                            sortedCards[i + 3].getNumber() - sortedCards[i].getNumber() == 3 &&
                            sortedCards[i + 4].getNumber() - sortedCards[i].getNumber() == 4 ;
        if (!isStraight) {
            continue;
        }
        double currentValue = 0;
        for (int j = 0; j < 5; j++) {
            currentValue += table.getValue(sortedCards[j]) / (pow(MAX_VALUE, -4 + j));
        }

        bestValue = (currentValue > bestValue) ? currentValue : bestValue;

    }

    return bestValue;

}

double Straight::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue = 0;
    vector<NumberCard> bestCombo;

    for (int i = 0; i < sortedCards.size() - 5; i++) {
        bool isStraight = sortedCards[i + 1].getNumber() - sortedCards[i].getNumber() == 1 &&
                            sortedCards[i + 2].getNumber() - sortedCards[i].getNumber() == 2 &&
                            sortedCards[i + 3].getNumber() - sortedCards[i].getNumber() == 3 &&
                            sortedCards[i + 4].getNumber() - sortedCards[i].getNumber() == 4 ;
        if (!isStraight) {
            continue;
        }
        double currentValue = 0;
        for (int j = 0; j < 5; j++) {
            currentValue += table.getValue(sortedCards[j]) / (pow(MAX_VALUE, -4 + j));
        }

        if(currentValue > bestValue) {
            bestValue = currentValue;
            auto first = sortedCards.begin() + i;
            auto end = sortedCards.begin() + i + 4;
            bestCombo = vector<NumberCard> (first, end);
            // sebenernya bisa langsung return
        }
    }

    return bestValue;
}
