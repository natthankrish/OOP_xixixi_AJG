#include "Reroll.hpp"
#include <iostream>

//======== Reroll ========
Reroll::Reroll() : abilityCommand("ability", "reroll"){

}   

Reroll::Reroll(string type, string name) : abilityCommand(type, name){

}   

Reroll::Reroll(const Reroll& x ) : abilityCommand(x){

}   

Reroll& Reroll::operator=(const Reroll& X){

} 

Reroll::~Reroll(){
    abilityCommand::~abilityCommand();
}    

void Reroll::execute() {
    cout<<"Reroll execute\n";
}

bool Reroll::continueToNextPlayer(){
    return true;
}