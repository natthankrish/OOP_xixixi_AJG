#include "TableCard.hpp"

TableCard::TableCard(): InventoryHolder("tablecard") {}

vector <NumberCard> TableCard::getCard() {
    return this->contents;
}

NumberCard TableCard::getCardAt(int i) {
    return this->contents[i];
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
    int count = 0;
    for (auto ptr = this->contents.begin(); ptr != this->contents.end(); ++ptr){
        cout << count+1 <<". " << ptr->getNumber() << " " << ptr->getColor() << endl;
        count++;
    }
    if (count == 0){
        cout << "Tidak ada kartu di atas meja." <<endl;
    }
}
