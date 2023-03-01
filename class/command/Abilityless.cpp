#include "Abilityless.hpp"
#include <iostream>

//======== Abilityless ========
Abilityless::Abilityless() : abilityCommand("ability", "abilityless"){

}   

Abilityless::Abilityless(string type, string name) : abilityCommand(type, name){

}   

Abilityless::Abilityless(const Abilityless& x ) : abilityCommand(x){

}   

Abilityless& Abilityless::operator=(const Abilityless& X){

} 

Abilityless::~Abilityless(){
    abilityCommand::~abilityCommand();
}    

void Abilityless::execute() {
    cout<<"Abilityless execute\n";
}
