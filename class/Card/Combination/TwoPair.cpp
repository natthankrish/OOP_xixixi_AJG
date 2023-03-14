#include "TwoPair.hpp"
#include <cmath>



double TwoPair::getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    double bestValue = 0;   
    for (int i = 0; i < sortedCards.size() - 3; i++) {
        bool isPair1 = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (!isPair1) 
            continue;
        
        for (int j = i + 2; j < sortedCards.size() - 1; j++) {
            bool isPair2 = sortedCards[j + 1].getNumber() == sortedCards[j].getNumber();
            if (!isPair2)
                continue;

            double currentValue = 0;
            for (int k = 0; k < 2; k++) {
                currentValue += table.getValue(sortedCards[i + k]) / pow(MAX_VALUE, 2 * k);
                currentValue += table.getValue(sortedCards[j + k]) / pow(MAX_VALUE, 2 * k + 1);
            }

            currentValue += table.getValue(sortedCards.back()) / pow(MAX_VALUE, 5);

            bestValue = (currentValue > bestValue) ? currentValue : bestValue;
        } 

    }
    return MAX_VALUE*2 + bestValue;
}

vector<NumberCard> TwoPair::getCombo(vector<NumberCard> sortedCards, LookUpTable table) {
    double bestValue = 0;
    vector<NumberCard> bestCombo;
    
    for (int i = 0; i < sortedCards.size() - 3; i++) {
        bool isPair1 = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (!isPair1) 
            continue;

        for (int j = i + 2; j < sortedCards.size() - 1; j++) {
            bool isPair2 = sortedCards[j + 1].getNumber() == sortedCards[j].getNumber();
            if (!isPair2)
                continue;
            
            double currentValue = 0;
            for (int k = 0; k < 2; k++) {
                currentValue += table.getValue(sortedCards[i + k]) / (pow(MAX_VALUE, -1 + k));
                currentValue += table.getValue(sortedCards[j + k]) / (pow(MAX_VALUE, -1 + k));
            }
            currentValue += table.getValue(sortedCards[sortedCards.size() - 1]) /MAX_VALUE;

            if (currentValue > bestValue) {
                bestValue = currentValue;
                vector<NumberCard> tempCombo = {sortedCards[i], sortedCards[i+1], sortedCards[j], sortedCards[j+1], sortedCards[sortedCards.size()-1]};
                bestCombo = tempCombo;
            }
        }
    }

    

    return bestCombo;
}
