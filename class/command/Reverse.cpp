#include "Reverse.hpp"
#include <iostream>

//======== Reverse ========
Reverse::Reverse() : abilityCommand("ability", "reverse", List<Player>(10)){

}   

Reverse::Reverse(string type, string name) : abilityCommand(type, name, List<Player>(10)){

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
bool Reverse::continueToNextPlayer(){
    return false;
}