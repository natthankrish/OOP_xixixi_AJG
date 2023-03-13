#include "Quadruple.hpp"
#include <iostream>

//======== Quadruple ========
Quadruple::Quadruple(string type, string name) : AbilityCommand(type, name){
}   

void Quadruple::execute(int prize, Round round) {
        cout << listPlayer.getElement(round.getIdxCurrentPlayer()-1).getName() << " melakukan QUADRUPLE! Point hadiah naik dari " << prize;
        prize *= 4; 
        cout << " menjadi " << prize << endl;
}

bool Quadruple::continueToNextPlayer(){
    return true;
}