#include "AbilityCommand.hpp"
#include <iostream>

//======== abilityCommand ========
AbilityCommand::AbilityCommand(string type, string name) : Command(type, name){
}

void AbilityCommand::execute(int prize) {
    cout<<"abilityCommand execute\n";
}

bool AbilityCommand::continueToNextPlayer(){
    return false;
}
