#include "AbilityCommand.hpp"
#include <iostream>

//======== abilityCommand ========
abilityCommand::abilityCommand() : Command(), listPlayer(List<Player>(10)){
    setType("ability");
}

abilityCommand::abilityCommand(string type, string name, List<Player> listOfPlayer) : Command(type, name), listPlayer(listOfPlayer) {

}

abilityCommand::abilityCommand(const abilityCommand& x) : Command(x), listPlayer(x.listPlayer) {

}

abilityCommand& abilityCommand::operator=(const abilityCommand& x) {

}

abilityCommand::~abilityCommand() {
    Command::~Command();
}

void abilityCommand::execute(Round round, int prize) {
    cout<<"abilityCommand execute\n";
}