#include "Quarter.hpp"
#include <iostream>

//======== Quarter ========
Quarter::Quarter() : abilityCommand("ability", "quarter"){

}   

Quarter::Quarter(string type, string name) : abilityCommand(type, name){

}   

Quarter::Quarter(const Quarter& x ) : abilityCommand(x){

}   

Quarter& Quarter::operator=(const Quarter& X){

} 

Quarter::~Quarter(){
    abilityCommand::~abilityCommand();
}    

void Quarter::execute() {
    cout<<"Quarter execute\n";
}
