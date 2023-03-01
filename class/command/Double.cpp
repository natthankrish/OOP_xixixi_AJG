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

} 

Double::~Double(){
    ordinaryCommand::~abilityCommand();
}    

void Double::execute() {
    cout<<"Double execute\n";
}
