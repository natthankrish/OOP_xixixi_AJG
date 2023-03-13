#include "Swap.hpp"
#include <iostream>

//======== Swap ========
Swap::Swap(string type, string name) : AbilityCommand(type, name){
}   

void Swap::execute() {
    cout<<"Swap execute\n";
}

bool Swap::continueToNextPlayer(){
    return false;
}