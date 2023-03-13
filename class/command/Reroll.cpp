#include "Reroll.hpp"
#include <iostream>

//======== Reroll ========
Reroll::Reroll() : abilityCommand("ability", "reroll", List<Player>(10)){

}   

Reroll::Reroll(string type, string name) : abilityCommand(type, name, List<Player>(10)){

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