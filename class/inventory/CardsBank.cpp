#include "CardsBank.hpp"
#include <time.h>

CardsBank::CardsBank(): InventoryHolder("CardsBank") {
    string color;
    vector<NumberCard> temp;
    for (int j = 0; j < 4; j++) {
        if (j == 0) {
            color = "merah";
        } else if (j == 1) {
            color = "kuning";
        } else if (j == 2) {
            color = "hijau";
        } else {
            color = "biru";
        }
        for (int i = 1; i < 14; i ++) {
            temp.push_back(NumberCard(i, color));
        }
    }

    //shuffling cards 
    srand(time(NULL));
    while (temp.size() > 0) {
        int idx = rand() % temp.size();
        this->element.push_back(temp[idx]);
        temp.erase(temp.begin() + idx);
    }
}

vector<NumberCard> CardsBank::getElement() {
    return this->element;
}


NumberCard CardsBank::getElementAt(int i) {
    return this->element[i];
}

void CardsBank::operator+(const NumberCard& cardItem) {
    this->element.push_back(cardItem);
}

void CardsBank::operator-(const NumberCard& element) {
    for (auto ptr = this->element.begin(); ptr != this->element.end(); ptr++) {
        if (ptr->getCardType() == element.getCardType() && ptr->getValue() == element.getValue()) {
            this->element.erase(ptr);
            return;
        }
    }
}

void CardsBank::bagiKartu(List<Player>& listPlayer) {
    for (int i = 0; i < listPlayer.getSize(); i++) {
        listPlayer[i] + this->element[0];
        this->element.erase(this->element.begin());
        listPlayer[i] + this->element[0];
        this->element.erase(this->element.begin());
    }
}

void CardsBank::seeCard() {
    for (auto ptr = this->element.begin(); ptr != this->element.end(); ptr++) {
        cout << ptr->getNumber() << " " << ptr->getColor() << endl;
    }
}

