#include <cmath>
#include "FullHouse.hpp"

double FullHouse::getValue(vector<NumberCard> _sortedCards, LookUpTable table){
    vector<NumberCard> sortedCards (_sortedCards);
    
    int bestTripleStartIndex = -1;
    for (int i = 0; i < sortedCards.size() - 2; i++) {
        bool isTriple = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i + 2].getNumber() == sortedCards[i].getNumber();
        if (isTriple) {
            bestTripleStartIndex = i;
        }
    }

    if (bestTripleStartIndex == -1)
        return 0;

    vector<NumberCard> bestTriple (sortedCards.begin() + bestTripleStartIndex, sortedCards.begin() + bestTripleStartIndex + 3);
    sortedCards.erase(sortedCards.begin() + bestTripleStartIndex, sortedCards.begin() + bestTripleStartIndex + 3);

    int bestDoubleIndex = -1;
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        bool isDouble = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (isDouble) {
            bestDoubleIndex = i;
        }
    }

    if (bestDoubleIndex == -1)
        return 0;

    vector<NumberCard> bestDouble (sortedCards.begin() + bestDoubleIndex, sortedCards.begin() + bestDoubleIndex + 2);
    
    double bestValue = 0;
    for (int i = 0; i < 2; i++) {
        bestValue += table.getValue(bestDouble[i]) / pow(MAX_VALUE, -4 + i);
    }
    for (int i = 0; i < 3; i++) {
        bestValue += table.getValue(bestTriple[i]) / pow(MAX_VALUE, -4 + i + 2);
    }

    return MAX_VALUE*6 + bestValue;

}
vector<NumberCard> FullHouse::getCombo(vector<NumberCard> _sortedCards, LookUpTable table){
    vector<NumberCard> sortedCards (_sortedCards);
    double bestValue = 0;
    
    int bestTripleStartIndex = -1;
    for (int i = 0; i < sortedCards.size() - 2; i++) {
        bool isTriple = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber() &&
                            sortedCards[i + 2].getNumber() == sortedCards[i].getNumber();
        if (isTriple) {
            bestTripleStartIndex = i;
        }
    }

    if (bestTripleStartIndex == -1)
        return vector<NumberCard>();

    vector<NumberCard> bestTriple (sortedCards.begin() + bestTripleStartIndex, sortedCards.begin() + bestTripleStartIndex + 3);
    sortedCards.erase(sortedCards.begin() + bestTripleStartIndex, sortedCards.begin() + bestTripleStartIndex + 3);

    int bestDoubleIndex = -1;
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        bool isDouble = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (isDouble) {
            bestDoubleIndex = i;
        }
    }

    if (bestDoubleIndex == -1)
        return vector<NumberCard>();

    vector<NumberCard> bestDouble (sortedCards.begin() + bestDoubleIndex, sortedCards.begin() + bestDoubleIndex + 2);
    
    for (int i = 0; i < 2; i++) {
        bestValue += table.getValue(bestDouble[i]) / pow(MAX_VALUE, -4 + i);
    }
    for (int i = 0; i < 3; i++) {
        bestValue += table.getValue(bestTriple[i]) / pow(MAX_VALUE, -4 + i + 2);
    }

    vector<NumberCard> bestFullHouse (bestDouble);
    bestFullHouse.insert(bestFullHouse.end(), bestTriple.begin(), bestTriple.end());

    return bestFullHouse;
}