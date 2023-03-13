#include "Double.hpp"
#include <iostream>

//======== Double ========
Double::Double() : ordinaryCommand("ordinary", "double"){

}   

Double::Double(string type, string name) : ordinaryCommand(type, name){

}   

Double::Double(const Double& x ) : ordinaryCommand(x){

}   

Double& Double::operator=(const Double& X){
    return *this;
} 

Double::~Double(){
    
}    

void Double::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout << listPlayer[playeridx-1].getName() << " melakukan DOUBLE! Point hadiah naik dari " << prize;
    prize *= 2; 
    cout << " menjadi " << prize << endl;
}

bool Double::continueToNextPlayer(){
    return true;
}
