#include "Reroll.hpp"
#include <iostream>

//======== Reroll ========
Reroll::Reroll() : AbilityCommand("ability", "reroll", List<Player>(10)){

}   

Reroll::Reroll(string type, string name) : AbilityCommand(type, name, List<Player>(10)){

}   

Reroll::Reroll(const Reroll& x ) : AbilityCommand(x){

}   

Reroll& Reroll::operator=(const Reroll& X){

} 

Reroll::~Reroll(){
    AbilityCommand::~AbilityCommand();
}    

void Reroll::execute() {
    cout<<"Reroll execute\n";
}

bool Reroll::continueToNextPlayer(){
    return true;
}