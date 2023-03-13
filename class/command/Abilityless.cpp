#include "Abilityless.hpp"
#include <iostream>

//======== Abilityless ========
Abilityless::Abilityless(string type, string name) : AbilityCommand(type, name){
}   

void Abilityless::execute() {
    cout<<"Abilityless execute\n";
}

bool Abilityless::continueToNextPlayer(){
    return true;
}