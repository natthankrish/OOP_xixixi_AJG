#include "Quadruple.hpp"
#include <iostream>

//======== Quadruple ========
Quadruple::Quadruple() : abilityCommand(){

}   

Quadruple::Quadruple(string type, string name) : abilityCommand(type, name){

}   

Quadruple::Quadruple(const Quadruple& x ) : abilityCommand(x){

}   

Quadruple& Quadruple::operator=(const Quadruple& X){

} 

Quadruple::~Quadruple(){
    abilityCommand::~abilityCommand();
}    

void Quadruple::execute() {
    cout<<"Quadruple execute\n";
}