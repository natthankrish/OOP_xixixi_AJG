#include "TwoPair.hpp"
#include <cmath>



double TwoPair::getValue(vector<NumberCard> _sortedCards, LookUpTable table) {
    vector<NumberCard> sortedCards (_sortedCards);

    int bestPairIndex = -1;
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        bool isPair = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (isPair) {
            bestPairIndex = i; 
        }
    }

    if (bestPairIndex == -1)
        return 0;

    vector<NumberCard> bestPair (sortedCards.begin() + bestPairIndex, sortedCards.begin() + bestPairIndex + 2);
    sortedCards.erase(sortedCards.begin() + bestPairIndex, sortedCards.begin() + bestPairIndex + 2);

    int secondBestPairIndex = -1;
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        bool isPair = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (isPair) {
            secondBestPairIndex = i;
        }
    }

    if (secondBestPairIndex == -1)
        return 0;

    vector<NumberCard> secondBestPair (sortedCards.begin() + secondBestPairIndex, sortedCards.begin() + secondBestPairIndex + 2);

    vector<NumberCard> bestTwoPair (secondBestPair);
    bestTwoPair.insert(bestTwoPair.end(), bestPair.begin(), bestPair.end());

    double bestValue = 0;
    for (int j = 0; j < 4; j++) {
        bestValue += table.getValue(bestTwoPair[j]) * (pow(MAX_VALUE, -4 + j));
    }

    return MAX_VALUE*2 + bestValue;
}

vector<NumberCard> TwoPair::getCombo(vector<NumberCard> _sortedCards, LookUpTable table) {
    vector<NumberCard> sortedCards (_sortedCards);
    double bestValue = 0;
    
    int bestPairIndex = -1;
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        bool isPair = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (isPair) {
            bestPairIndex = i; 
        }
    }

    if (bestPairIndex == -1)
        return vector<NumberCard>();

    vector<NumberCard> bestPair (sortedCards.begin() + bestPairIndex, sortedCards.begin() + bestPairIndex + 2);
    sortedCards.erase(sortedCards.begin() + bestPairIndex, sortedCards.begin() + bestPairIndex + 2);

    int secondBestPairIndex = -1;
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        bool isPair = sortedCards[i + 1].getNumber() == sortedCards[i].getNumber();
        if (isPair) {
            secondBestPairIndex = i;
        }
    }

    if (secondBestPairIndex == -1)
        return vector<NumberCard>();

    vector<NumberCard> secondBestPair (sortedCards.begin() + secondBestPairIndex, sortedCards.begin() + secondBestPairIndex + 2);

    vector<NumberCard> bestTwoPair (secondBestPair);
    bestTwoPair.insert(bestTwoPair.end(), bestPair.begin(), bestPair.end());

    return bestTwoPair;
}
