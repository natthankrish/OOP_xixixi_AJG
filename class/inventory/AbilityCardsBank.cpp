#include "AbilityCardsBank.hpp"
#include <time.h>

AbilityCardsBank::AbilityCardsBank() {
    vector<Card> temp;
    Card *ptr;
    AbilityCard eltemp("Re-roll");
    ptr = &eltemp;
    temp.push_back(*ptr);

    eltemp = AbilityCard("Quadruple");
    ptr = &eltemp;
    temp.push_back(*ptr);

    eltemp = AbilityCard("Quarter");
    ptr = &eltemp;
    temp.push_back(*ptr);

    eltemp = AbilityCard("Reverse");
    ptr = &eltemp;
    temp.push_back(*ptr);

    eltemp = AbilityCard("Quadraple");
    ptr = &eltemp;
    temp.push_back(*ptr);

    eltemp = AbilityCard("Swap Card");
    ptr = &eltemp;
    temp.push_back(*ptr);

    eltemp = AbilityCard("Switch");
    ptr = &eltemp;
    temp.push_back(*ptr);

    eltemp = AbilityCard("Abilityless");
    ptr = &eltemp;
    temp.push_back(*ptr);

    //shuffling cards 
    srand(time(NULL));
    while (temp.size() > 0) {
        int idx = rand() % temp.size();
        this->element.push_back(temp[idx]);
        temp.erase(temp.begin() + idx);
    }    
}

vector<Card> AbilityCardsBank::getElement() {
    return this->element;
} 

Card AbilityCardsBank::getElementAt(int i) {
    return this->element[i];
}

void AbilityCardsBank::operator+(const Card& cardItem) {
    this->element.push_back(cardItem);
}

void AbilityCardsBank::operator-(const Card& element) {
    for (auto ptr = this->element.begin(); ptr != this->element.end(); ptr++) {
        if (ptr->getCardType() == element.getCardType() && ptr->getValue() == element.getValue()) {
            this->element.erase(ptr);
            return;
        }
    }
}