#include "AbilityCard.hpp"

#include <string>
using namespace std;

AbilityCard::AbilityCard(): abilityName("none") {}

AbilityCard::AbilityCard(string name): abilityName(name) {

}

AbilityCard& AbilityCard::operator=(const AbilityCard& ac){
    this->abilityName = ac.abilityName;
    return *this;
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

bool AbilityCard::operator!= (const AbilityCard& other) {
    return this->abilityName != other.abilityName;
}