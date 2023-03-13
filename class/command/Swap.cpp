#include "Swap.hpp"
#include <iostream>

//======== Swap ========
Swap::Swap() : AbilityCommand("ability", "swap"){

}   

Swap::Swap(string type, string name) : AbilityCommand(type, name){

}   

Swap::Swap(const Swap& x ) : AbilityCommand(x){

}   

Swap& Swap::operator=(const Swap& X){

} 

Swap::~Swap(){
    AbilityCommand::~AbilityCommand();
}    

void Swap::execute() {
    cout<<"Swap execute\n";
}

bool Swap::continueToNextPlayer(){
    return false;
}