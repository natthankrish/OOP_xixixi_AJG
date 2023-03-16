#include "AbilityCardsBank.hpp"
#include <time.h>

AbilityCardsBank::AbilityCardsBank() {
    vector<AbilityCard> temp;
    
    temp.push_back(AbilityCard("Reroll"));
    temp.push_back(AbilityCard("Quadruple"));
    temp.push_back(AbilityCard("Quarter"));
    temp.push_back(AbilityCard("Reverse"));
    temp.push_back(AbilityCard("Swap"));
    temp.push_back(AbilityCard("Switch"));
    temp.push_back(AbilityCard("Abilityless"));

    //shuffling cards 
    srand(time(NULL));
    while (temp.size() > 0) {
        int idx = rand() % temp.size();
        this->element.push_back(temp[idx]);
        temp.erase(temp.begin() + idx);
    }    
}

vector<AbilityCard> AbilityCardsBank::getElement() {
    return this->element;
} 

AbilityCard AbilityCardsBank::getElementAt(int i) {
    return this->element[i];
}

void AbilityCardsBank::operator+(const AbilityCard& cardItem) {
    this->element.push_back(cardItem);
}

void AbilityCardsBank::operator-(const AbilityCard& element) {
    for (auto ptr = this->element.begin(); ptr != this->element.end(); ptr++) {
        if (ptr->getCardType() == element.getCardType() && ptr->getValue() == element.getValue()) {
            this->element.erase(ptr);
            return;
        }
    }
}

void AbilityCardsBank::bagiAbility(List<Player>& listPlayer) {
    for (int i = 0; i < listPlayer.getSize(); i++) {
        listPlayer[i] + this->element[0];
        this->element.erase(this->element.begin());
    }
}