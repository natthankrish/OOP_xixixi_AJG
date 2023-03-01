#include "OrdinaryCommand.hpp"
#include <iostream>

//======== ordinaryCommand ========
ordinaryCommand::ordinaryCommand() : Command(){
    setType("ordinary");
}  

ordinaryCommand::ordinaryCommand(string type, string name) : Command(type, name){

}  

ordinaryCommand::ordinaryCommand(const ordinaryCommand& x ) : Command(x){

}   

ordinaryCommand& ordinaryCommand::operator=(const ordinaryCommand& X){

} 

ordinaryCommand::~ordinaryCommand(){
    Command::~Command();
}                               

void ordinaryCommand::execute() {
    cout<<"ordinaryCommand execute\n";
}