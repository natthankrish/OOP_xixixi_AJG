#include "Flush.hpp"
#include <cmath>

double Flush::getValue(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue = 0;
    
    for (int i = 0; i < sortedCards.size() - 5; i++) {
        bool isFlush = sortedCards[i + 1].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i + 2].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i + 3].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i + 4].getColor() == sortedCards[i].getColor();
        if (!isFlush) 
            continue;

        double currentValue = 0;
        for (int i = 0; i < 5; i++) {
            currentValue += table.getValue(sortedCards[i]) / (pow(MAX_VALUE, -4 + i));
        }

        bestValue = (currentValue > bestValue) ? currentValue : bestValue;
    }
    
    return bestValue;

}
vector<NumberCard> Flush::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue = 0;
    vector<NumberCard> bestCombo;

    
    for (int i = 0; i < sortedCards.size() - 5; i++) {
        bool isFlush = sortedCards[i + 1].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i + 2].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i + 3].getColor() == sortedCards[i].getColor() &&
                        sortedCards[i + 4].getColor() == sortedCards[i].getColor();
        if (!isFlush) 
            continue;

        double currentValue = 0;
        for (int j = 0; j < 5; j++) {
            currentValue += table.getValue(sortedCards[j]) / (pow(MAX_VALUE, -4 + j));
        }

        if(currentValue > bestValue) {
            bestValue = currentValue;
            auto first = sortedCards.begin() + i;
            auto end = sortedCards.begin() + i + 5;
            bestCombo = vector<NumberCard> (first, end);
            // sebenernya bisa langsung return
        }
        
    }
    
    return bestCombo;
}