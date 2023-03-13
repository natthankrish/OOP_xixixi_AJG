#include "Switch.hpp"
#include <iostream>

//======== Switch ========
Switch::Switch() : AbilityCommand("ability", "switch"){

}   

Switch::Switch(string type, string name) : AbilityCommand(type, name){

}   

Switch::Switch(const Switch& x ) : AbilityCommand(x){

}   

Switch& Switch::operator=(const Switch& X){

} 

Switch::~Switch(){
    AbilityCommand::~AbilityCommand();
}    

void Switch::execute() {
    cout<<"Switch execute\n";
}

bool Switch::continueToNextPlayer(){
    return false;
}