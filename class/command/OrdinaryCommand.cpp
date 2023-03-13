#include "OrdinaryCommand.hpp"
#include <iostream>

//======== ordinaryCommand ========
ordinaryCommand::ordinaryCommand() : Command() {
    setType("ordinary");
}  

ordinaryCommand::ordinaryCommand(string type, string name) : Command(type, name) {

}  

ordinaryCommand::ordinaryCommand(const ordinaryCommand& x ) : Command(x) {

}   

ordinaryCommand& ordinaryCommand::operator=(const ordinaryCommand& X){
    return *this;
} 

ordinaryCommand::~ordinaryCommand(){
    Command::~Command();
}                               

void ordinaryCommand::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout<<"ordinary Command execute\n";
}

bool ordinaryCommand::continueToNextPlayer(){
    return false;
}
