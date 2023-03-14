#include "StraightFlush.hpp"
#include <cmath>

double StraightFlush::getValue(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue = 0;
    for (int i = 0 ; i <sortedCards.size() -4 ; i++){
        bool isStraightFlush =  sortedCards[i+1].getNumber() == sortedCards[i].getNumber() +1 &&
                                sortedCards[i+2].getNumber() == sortedCards[i].getNumber() +2 &&
                                sortedCards[i+3].getNumber() == sortedCards[i].getNumber() +3 &&
                                sortedCards[i+4].getNumber() == sortedCards[i].getNumber() +4 &&
                                sortedCards[i+1].getColor() == sortedCards[i].getColor()  && 
                                sortedCards[i+2].getColor() == sortedCards[i].getColor()  &&             
                                sortedCards[i+3].getColor() == sortedCards[i].getColor()  && 
                                sortedCards[i+4].getColor() == sortedCards[i].getColor()  ; 
        if (!isStraightFlush)
            continue;
        double currentValue = 0;
        for (int j =0; j < 5; j++) {
            currentValue += table.getValue(sortedCards[i + j]) / (pow(MAX_VALUE, -4 + j));
        }
        bestValue = (currentValue > bestValue) ? currentValue : bestValue;
    }

    return bestValue;                                        

}
vector<NumberCard> StraightFlush::getCombo(vector<NumberCard> sortedCards, LookUpTable table){
    double bestValue=0 ;
    vector<NumberCard> bestCombo;

    for (int i = 0 ; i <sortedCards.size() -4 ; i++){
        bool isStraightFlush =  sortedCards[i+1].getNumber() == sortedCards[i].getNumber() +1 &&
                                sortedCards[i+2].getNumber() == sortedCards[i].getNumber() +2 &&
                                sortedCards[i+3].getNumber() == sortedCards[i].getNumber() +3 &&
                                sortedCards[i+4].getNumber() == sortedCards[i].getNumber() +4 &&
                                sortedCards[i+1].getColor() == sortedCards[i].getColor()  && 
                                sortedCards[i+2].getColor() == sortedCards[i].getColor()  &&             
                                sortedCards[i+3].getColor() == sortedCards[i].getColor()  && 
                                sortedCards[i+4].getColor() == sortedCards[i].getColor()  ; 
        if (!isStraightFlush)
            continue;
        double currentValue = 0;
        for (int j =0; j < 5; j++){
            currentValue += table.getValue(sortedCards[i + j]) / (pow(MAX_VALUE, -4 + j));
        }
        if (currentValue>bestValue){
            bestValue=currentValue;
            auto first = sortedCards.begin() + i;
            auto end = sortedCards.begin() + i + 5;
            bestCombo = vector<NumberCard>(first, end);
        }
    }
    return bestCombo;
}
