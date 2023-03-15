#include "TableCard.hpp"

TableCard::TableCard(): InventoryHolder("tablecard") {}

vector <NumberCard> TableCard::getCard() {
    return this->contents;
}

void TableCard::operator+(const NumberCard& card) {
    this->contents.insert(this->contents.begin(), card);
}

void TableCard::operator-(const NumberCard& card) {
    int i = 0;
    while (i < this->contents.size()) {
        if (this->contents[i] == card) {
            this->contents.erase(this->contents.begin() + i);
            return;
        }
    }
    throw CardNotFoundException();
}

NumberCard& TableCard::Top() {
    return *(this->contents.begin());
}


