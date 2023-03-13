#include "Reverse.hpp"
#include <iostream>

//======== Reverse ========
Reverse::Reverse() : AbilityCommand("ability", "reverse"){

}   

Reverse::Reverse(string type, string name) : AbilityCommand(type, name){

}   

Reverse::Reverse(const Reverse& x ) : AbilityCommand(x){

}   

Reverse& Reverse::operator=(const Reverse& X){

} 

Reverse::~Reverse(){
    AbilityCommand::~AbilityCommand();
}    

void Reverse::execute() {
    cout<<"Reverse execute\n";
}
bool Reverse::continueToNextPlayer(){
    return false;
}