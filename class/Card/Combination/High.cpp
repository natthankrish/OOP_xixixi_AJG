#include "High.hpp"

double getValue(vector<NumberCard> sortedCards, LookUpTable table) {
    NumberCard highCard = sortedCards.back();
    return table.getValue(highCard);
}

vector<NumberCard> getCombo(vector<NumberCard> sortedCards, LookUpTable table) {
    return vector<NumberCard> {sortedCards.back()};
}
