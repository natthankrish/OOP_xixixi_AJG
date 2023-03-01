#include "Reverse.hpp"
#include <iostream>

//======== Reverse ========
Reverse::Reverse() : abilityCommand("ability", "reverse"){

}   

Reverse::Reverse(string type, string name) : abilityCommand(type, name){

}   

Reverse::Reverse(const Reverse& x ) : abilityCommand(x){

}   

Reverse& Reverse::operator=(const Reverse& X){

} 

Reverse::~Reverse(){
    abilityCommand::~abilityCommand();
}    

void Reverse::execute() {
    cout<<"Reverse execute\n";
}
