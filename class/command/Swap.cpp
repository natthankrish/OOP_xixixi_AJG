#include "Swap.hpp"
#include <iostream>

//======== Swap ========
Swap::Swap() : abilityCommand("ability", "swap"){

}   

Swap::Swap(string type, string name) : abilityCommand(type, name){

}   

Swap::Swap(const Swap& x ) : abilityCommand(x){

}   

Swap& Swap::operator=(const Swap& X){

} 

Swap::~Swap(){
    abilityCommand::~abilityCommand();
}    

void Swap::execute() {
    cout<<"Swap execute\n";
}

bool Swap::continueToNextPlayer(){
    return false;
}