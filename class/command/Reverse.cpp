#include "Reverse.hpp"
#include <iostream>

//======== Reverse ========
Reverse::Reverse() : AbilityCommand("ability", "reverse", List<Player>(10)){

}   

Reverse::Reverse(string type, string name) : AbilityCommand(type, name, List<Player>(10)){

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