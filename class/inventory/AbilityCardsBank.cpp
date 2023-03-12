#include "AbilityCardsBank.hpp"
#include <time.h>

AbilityCardsBank::AbilityCardsBank(): InventoryHolder("AbilityCardsBank") {
    vector<AbilityCard> temp;
    temp.push_back(AbilityCard("Re-roll"));
    temp.push_back(AbilityCard("Quadraple"));
    temp.push_back(AbilityCard("Quarter"));
    temp.push_back(AbilityCard("Reverse"));
    temp.push_back(AbilityCard("Swap Card"));
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