#include "OrdinaryCommand.hpp"
#include <iostream>

//======== ordinaryCommand ========
OrdinaryCommand::OrdinaryCommand() : Command() {
    setType("ordinary");
}  

OrdinaryCommand::OrdinaryCommand(string type, string name) : Command(type, name) {

}  

OrdinaryCommand::OrdinaryCommand(const OrdinaryCommand& x ) : Command(x) {

}   

OrdinaryCommand& OrdinaryCommand::operator=(const OrdinaryCommand& X){
    return *this;
} 

OrdinaryCommand::~OrdinaryCommand(){
    Command::~Command();
}                               

void OrdinaryCommand::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout<<"ordinary Command execute\n";
}

bool OrdinaryCommand::continueToNextPlayer(){
    return false;
}
