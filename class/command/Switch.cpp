#include "Switch.hpp"
#include <iostream>

//======== Switch ========
Switch::Switch() : abilityCommand(){

}   

Switch::Switch(string type, string name) : abilityCommand(type, name){

}   

Switch::Switch(const Switch& x ) : abilityCommand(x){

}   

Switch& Switch::operator=(const Switch& X){

} 

Switch::~Switch(){
    abilityCommand::~abilityCommand();
}    

void Switch::execute() {
    cout<<"Switch execute\n";
}