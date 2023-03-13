#include "Double.hpp"
#include <iostream>

//======== Double ========
Double::Double() : OrdinaryCommand("ordinary", "double"){

}   

Double::Double(string type, string name) : OrdinaryCommand(type, name){

}   

Double::Double(const Double& x ) : OrdinaryCommand(x){

}   

Double& Double::operator=(const Double& X){

} 

Double::~Double(){
    OrdinaryCommand::~abilityCommand();
}    

void Double::execute(int prize, Round round) {
    cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan DOUBLE! Point hadiah naik dari " << prize;
    prize *= 2; 
    cout << " menjadi " << prize << endl;
}

bool Double::continueToNextPlayer(){
    return true;
}
