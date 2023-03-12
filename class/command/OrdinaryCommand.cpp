#include "OrdinaryCommand.hpp"
#include <iostream>

//======== ordinaryCommand ========
ordinaryCommand::ordinaryCommand() : Command(), listPlayer(List<Player>(10)){
    setType("ordinary");
}  

ordinaryCommand::ordinaryCommand(string type, string name, List<Player> listOfPlayer) : Command(type, name), listPlayer(listOfPlayer){

}  

ordinaryCommand::ordinaryCommand(const ordinaryCommand& x ) : Command(x), listPlayer(x.listPlayer){

}   

ordinaryCommand& ordinaryCommand::operator=(const ordinaryCommand& X){

} 

ordinaryCommand::~ordinaryCommand(){
    Command::~Command();
}                               

void ordinaryCommand::execute(Round round, int prize) {
    cout<<"ordinaryCommand execute\n";
}

bool ordinaryCommand::continueToNextPlayer(){
    return false;
}
