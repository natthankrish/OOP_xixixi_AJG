#include "AbilityCard.hpp"

#include <string>
using namespace std;

AbilityCard::AbilityCard(string name): abilityName(name) {

}

string AbilityCard::getAbilityName(){
    return this->abilityName;
}

void AbilityCard::setAbilityName(string abilityName){
    this->abilityName = abilityName;
}

void AbilityCard::useCard(){
    //
}