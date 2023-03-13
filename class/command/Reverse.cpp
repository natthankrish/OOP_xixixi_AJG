#include "Reverse.hpp"
#include <iostream>

//======== Reverse ========
Reverse::Reverse(string type, string name) : AbilityCommand(type, name){
}   

void Reverse::execute() {
    cout<<"Reverse execute\n";
}
bool Reverse::continueToNextPlayer(){
    return false;
}