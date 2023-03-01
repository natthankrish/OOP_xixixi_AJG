#include "Half.hpp"
#include <iostream>

//======== Half ========
Half::Half() : ordinaryCommand(){

}   

Half::Half(string type, string name) : ordinaryCommand(type, name){

}   

Half::Half(const Half& x ) : ordinaryCommand(x){

}   

Half& Half::operator=(const Half& X){

} 

Half::~Half(){
    ordinaryCommand::~abilityCommand();
}    

void Half::execute() {
    cout<<"Half execute\n";
}