#include "Pair.hpp"
#include <cmath>

double Pair::getValue(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue = 0;
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        for (int j = i + 1; j < sortedCards.size(); j++) {
            bool isPair = sortedCards[j].getNumber() == sortedCards[i].getNumber();
            if(!isPair)
                continue;
            double currentValue = 0;
            for (int k = 0; k<2;k++){
                currentValue += table.getValue(sortedCards[i+k])/(pow(MAX_VALUE, -1+k));
            }
            bestValue = (currentValue>bestValue) ? currentValue : bestValue;
        }
    }

    return MAX_VALUE + bestValue;
}
vector<NumberCard> Pair::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue = 0;
    vector<NumberCard> bestCombo;
    
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        bool isPair = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (!isPair)
            continue;

        double currentValue = 0;
        currentValue += table.getValue(sortedCards[i]) / pow(MAX_VALUE, 1);

        for (int j = 0; j < 3; j++) {
            if (j == i || j == i + 1)
                continue;
            currentValue += table.getValue(sortedCards[j]) / (pow(MAX_VALUE, -1 + j));
        }

        if (currentValue > bestValue) {
            bestValue = currentValue;
            auto first = sortedCards.begin() + i;
            auto end = sortedCards.begin() + i + 2;
            bestCombo = vector<NumberCard> (first, end);
            for (int j = 0; j < sortedCards.size(); j++) {
                if (j == i || j == i+1) 
                    continue;
                if (bestCombo.size() == 4)
                    break;
                bestCombo.push_back(sortedCards[j]);
            }
        } 
    }
    return bestCombo;
}