#include "AbilityCommand.hpp"
#include <iostream>

//======== abilityCommand ========
AbilityCommand::AbilityCommand() : Command(), listPlayer(List<Player>(10)){
    setType("ability");
}

AbilityCommand::AbilityCommand(string type, string name, List<Player> listOfPlayer) : Command(type, name), listPlayer(listOfPlayer) {

}

AbilityCommand::AbilityCommand(const AbilityCommand& x) : Command(x), listPlayer(x.listPlayer) {

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
