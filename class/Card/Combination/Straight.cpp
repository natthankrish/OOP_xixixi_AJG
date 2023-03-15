#include "Straight.hpp"
#include <cmath>


double Straight::getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    vector<NumberCard> bestCombo;
    int walker = sortedCards.size() - 1;
    while (walker >= 0 && bestCombo.size() < 5) {
        if (bestCombo.size() == 0) {
            bestCombo.insert(bestCombo.begin(), sortedCards[walker]);
        } else {
            if (!(bestCombo.front().getNumber() == sortedCards[walker].getNumber())) {
                if (bestCombo.front().getNumber() - sortedCards[walker].getNumber() == 1) {
                    bestCombo.insert(bestCombo.begin(), sortedCards[walker]);
                } else {
                    bestCombo.clear();
                    bestCombo.insert(bestCombo.begin(), sortedCards[walker]);
                }    
            }
        }
        walker--;
    }

    if (bestCombo.size() == 5) {
        double bestValue = 0;
        for (int j = 0; j < 5; j++) {
            bestValue += table.getValue(bestCombo[j]) * (pow(MAX_VALUE, -5 + j));
        }
        return MAX_VALUE*4 + bestValue;
    } else {
        return 0;
    }
    
}


vector<NumberCard> Straight::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue = 0;
    vector<NumberCard> bestCombo;
    int walker = sortedCards.size() - 1;
    while (walker >= 0 && bestCombo.size() < 5) {
        if (bestCombo.size() == 0) {
            bestCombo.insert(bestCombo.begin(), sortedCards[walker]);
        } else {
            if (!(bestCombo.front().getNumber() == sortedCards[walker].getNumber())) {
                if (bestCombo.front().getNumber() - sortedCards[walker].getNumber() == 1) {
                    bestCombo.insert(bestCombo.begin(), sortedCards[walker]);
                } else {
                    bestCombo.clear();
                    bestCombo.insert(bestCombo.begin(), sortedCards[walker]);
                }    
            }
        }
        walker--;
    }
    
    return bestCombo.size() == 5 ? bestCombo : vector<NumberCard>();
}
