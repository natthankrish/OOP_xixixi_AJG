#include "High.hpp"
#include <cmath>
double High::getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    NumberCard highCard = sortedCards.back();
    return table.getValue(highCard) * std::pow(MAX_VALUE, -1);
}


vector<NumberCard> High::getCombo(vector<NumberCard> sortedCards, LookUpTable table) {
    return vector<NumberCard> {sortedCards.back()};
}
