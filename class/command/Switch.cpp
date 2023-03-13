#include "Switch.hpp"
#include <iostream>

//======== Switch ========
Switch::Switch(string type, string name) : AbilityCommand(type, name){

}   

void Switch::execute() {
    cout<<"Switch execute\n";
}

bool Switch::continueToNextPlayer(){
    return false;
}