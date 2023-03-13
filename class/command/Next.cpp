#include "Next.hpp"
#include <iostream>

//======== Next ========
Next::Next() : OrdinaryCommand("ordinary","next"){

}   

Next::Next(string type, string name) : OrdinaryCommand(type, name){

}   

Next::Next(const Next& x ) : OrdinaryCommand(x){

}   

Next& Next::operator=(const Next& X){
    return *this;
} 

Next::~Next(){
    OrdinaryCommand::~OrdinaryCommand();
}    

void Next::execute(List<Player>& listPlayer, int playeridx, int& prize, CardsBank& cardsbank, AbilityCardsBank& abilitycardsbank) {
    cout << "Giliran dilanjut ke player selanjutnya." << endl;
}

bool Next::continueToNextPlayer(){
    return true;
}