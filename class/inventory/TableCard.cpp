#include "TableCard.hpp"

TableCard::TableCard(): InventoryHolder("tablecard") {}

vector <NumberCard> TableCard::getCard() {
    return this->contents;
}

void TableCard::operator+(const NumberCard& card) {
    if (this->contents.size() >= CAPACITY) {
        throw TableCardFullException();
    }

    this->contents.push_back(card);
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

void TableCard::seeCard() {
    for (auto ptr = this->contents.begin(); ptr != this->contents.end(); ++ptr){
        cout << ptr->getNumber() << " " << ptr->getColor() << endl;
    }
}
