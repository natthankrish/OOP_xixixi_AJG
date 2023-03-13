#include "AbilityCommand.hpp"
#include <iostream>

//======== abilityCommand ========
AbilityCommand::AbilityCommand() : Command() {
    setType("ability");
}

AbilityCommand::AbilityCommand(string type, string name) : Command(type, name) {

}

AbilityCommand::AbilityCommand(const AbilityCommand& x) : Command(x) {

}

AbilityCommand& AbilityCommand::operator=(const AbilityCommand& x) {

}

AbilityCommand::~AbilityCommand() {
    Command::~Command();
}

void AbilityCommand::execute(int prize) {
    cout<<"abilityCommand execute\n";
}

bool AbilityCommand::continueToNextPlayer(){
    return false;
}
