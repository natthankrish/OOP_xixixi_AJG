#include "AbilityCommand.hpp"
#include <iostream>

//======== abilityCommand ========
abilityCommand::abilityCommand() : Command(){
    setType("ability");
}

abilityCommand::abilityCommand(string type, string name) : Command(type, name) {

}

abilityCommand::abilityCommand(const abilityCommand& x) : Command(x) {

}

abilityCommand& abilityCommand::operator=(const abilityCommand& x) {

}

abilityCommand::~abilityCommand() {
    Command::~Command();
}

void abilityCommand::execute() {
    cout<<"abilityCommand execute\n";
}