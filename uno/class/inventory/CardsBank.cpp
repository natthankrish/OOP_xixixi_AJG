#include "CardsBank.hpp"
#include <time.h>

CardsBank::CardsBank(): InventoryHolder("CardsBank") {
    string color;
    vector<NumberCard> temp;
    for (int k = 0; k < 2; k++) {
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
            for (int i = 1; i < 16; i ++) {
                if (i < 14) {
                    if (i != 10) {
                        temp.push_back(NumberCard(i, color));
                    }
                } else {
                    if (k == 1) {
                        temp.push_back(NumberCard(i, "none"));
                    }
                }
            }
        }
    }

    temp.push_back(NumberCard(0, "merah"));
    temp.push_back(NumberCard(0, "kuning"));
    temp.push_back(NumberCard(0, "hijau"));
    temp.push_back(NumberCard(0, "biru"));


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

NumberCard CardsBank::operator--() {
    NumberCard temp = this->element[0];
    this->element.erase(this->element.begin());
    return temp;
}

void CardsBank::bagiKartu(List<Player>& listPlayer) {
    for (int i = 0; i < listPlayer.getSize(); i++) {
        for (int j = 0; j < 7; j++) {
            listPlayer[i] + this->element[0];
            this->element.erase(this->element.begin());
        }
    }
}

void CardsBank::seeCard() {
    for (auto ptr = this->element.begin(); ptr != this->element.end(); ptr++) {
        cout << ptr->getNumber() << " " << ptr->getColor() << endl;
    }
}

