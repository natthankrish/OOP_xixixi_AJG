#include "OrdinaryCommand.hpp"
#include <iostream>

//======== ordinaryCommand ========
OrdinaryCommand::OrdinaryCommand() : Command(){
    setType("ordinary");
}  

OrdinaryCommand::OrdinaryCommand(string type, string name) : Command(type, name){

}  

OrdinaryCommand::OrdinaryCommand(const OrdinaryCommand& x ) : Command(x){

}   

OrdinaryCommand& OrdinaryCommand::operator=(const OrdinaryCommand& X){

} 

OrdinaryCommand::~OrdinaryCommand(){
    Command::~Command();
}                               

void OrdinaryCommand::execute(int prize) {
    cout<<"ordinaryCommand execute\n";
}

bool OrdinaryCommand::continueToNextPlayer(){
    return false;
}
