#include "StraightFlush.hpp"
#include <cmath>

double StraightFlush::getValue(vector<NumberCard> sortedCards, LookUpTable table){
    for (int i = sortedCards.size() - 1; i >= 4; i--) {
        bool isStraightFlush =  sortedCards[i-1].getNumber() == sortedCards[i].getNumber() - 1 &&
                                sortedCards[i-2].getNumber() == sortedCards[i].getNumber() - 2 &&
                                sortedCards[i-3].getNumber() == sortedCards[i].getNumber() - 3 &&
                                sortedCards[i-4].getNumber() == sortedCards[i].getNumber() - 4 &&
                                sortedCards[i-1].getColor() == sortedCards[i].getColor()  && 
                                sortedCards[i-2].getColor() == sortedCards[i].getColor()  &&             
                                sortedCards[i-3].getColor() == sortedCards[i].getColor()  && 
                                sortedCards[i-4].getColor() == sortedCards[i].getColor()  ; 
        if (isStraightFlush) {
            vector<NumberCard> bestCombo = vector<NumberCard> (sortedCards.begin() + i - 4, sortedCards.begin() + i + 1);
            double bestValue;
            for (int j = 0; j < 5; j++) {
                bestValue += table.getValue(bestCombo[j]) * (pow(MAX_VALUE, -5 + j));
            }
            return MAX_VALUE*8 + bestValue;
        }
    }                                     
    return 0;
}
vector<NumberCard> StraightFlush::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    for (int i = sortedCards.size() - 1; i >= 4; i--) {
        bool isStraightFlush =  sortedCards[i-1].getNumber() == sortedCards[i].getNumber() - 1 &&
                                sortedCards[i-2].getNumber() == sortedCards[i].getNumber() - 2 &&
                                sortedCards[i-3].getNumber() == sortedCards[i].getNumber() - 3 &&
                                sortedCards[i-4].getNumber() == sortedCards[i].getNumber() - 4 &&
                                sortedCards[i-1].getColor() == sortedCards[i].getColor()  && 
                                sortedCards[i-2].getColor() == sortedCards[i].getColor()  &&             
                                sortedCards[i-3].getColor() == sortedCards[i].getColor()  && 
                                sortedCards[i-4].getColor() == sortedCards[i].getColor()  ; 
        if (isStraightFlush) {
            vector<NumberCard> bestCombo = vector<NumberCard> (sortedCards.begin() + i - 4, sortedCards.begin() + i + 1);
            return bestCombo;
        }
    }
    
    return vector<NumberCard>();
}
