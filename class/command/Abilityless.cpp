#include "Abilityless.hpp"
#include <iostream>

//======== Abilityless ========
Abilityless::Abilityless() : AbilityCommand("ability", "abilityless", List<Player>(10)){

}   

Abilityless::Abilityless(string type, string name) : AbilityCommand(type, name, List<Player>(10)){

}   

Abilityless::Abilityless(const Abilityless& x ) : AbilityCommand(x){

}   

Abilityless& Abilityless::operator=(const Abilityless& X){

} 

Abilityless::~Abilityless(){
    AbilityCommand::~AbilityCommand();
}    

void Abilityless::execute() {
    cout<<"Abilityless execute\n";
}

bool Abilityless::continueToNextPlayer(){
    return true;
}