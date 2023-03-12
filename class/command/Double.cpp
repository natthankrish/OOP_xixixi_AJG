#include "Double.hpp"
#include <iostream>

//======== Double ========
Double::Double() : ordinaryCommand("ordinary", "double", List<Player>(10)){

}   

Double::Double(string type, string name, List<Player> listPlayer) : ordinaryCommand(type, name, listPlayer){

}   

Double::Double(const Double& x ) : ordinaryCommand(x){

}   

Double& Double::operator=(const Double& X){

} 

Double::~Double(){
    ordinaryCommand::~abilityCommand();
}    

void Double::execute(int prize, Round round) {
    cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan DOUBLE! Point hadiah naik dari " << prize;
    prize *= 2; 
    cout << " menjadi " << prize << endl;
}

bool Double::continueToNextPlayer(){
    return true;
}
