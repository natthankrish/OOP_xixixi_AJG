#include "Reroll.hpp"
#include <iostream>

//======== Reroll ========
Reroll::Reroll(string type, string name) : AbilityCommand(type, name){
}

void Reroll::execute() {
    cout<<"Reroll execute\n";
}

bool Reroll::continueToNextPlayer(){
    return true;
}