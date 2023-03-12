#include "Next.hpp"
#include <iostream>

//======== Next ========
Next::Next() : ordinaryCommand("ordinary","next", List<Player>(10)){

}   

Next::Next(string type, string name, List<Player> listPlayer) : ordinaryCommand(type, name, listPlayer){

}   

Next::Next(const Next& x ) : ordinaryCommand(x){

}   

Next& Next::operator=(const Next& X){

} 

Next::~Next(){
    ordinaryCommand::~ordinaryCommand();
}    

void Next::execute(Round round, int prize) {
    cout << "Giliran dilanjut ke player selanjutnya." << endl;
}

bool Next::continueToNextPlayer(){
    return true;
}