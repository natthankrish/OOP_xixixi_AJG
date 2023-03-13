#include "Next.hpp"
#include <iostream>

//======== Next ========
Next::Next() : ordinaryCommand("ordinary","next"){

}   

Next::Next(string type, string name) : ordinaryCommand(type, name){

}   

Next::Next(const Next& x ) : ordinaryCommand(x){

}   

Next& Next::operator=(const Next& X){
    return *this;
} 

Next::~Next(){
    ordinaryCommand::~ordinaryCommand();
}    

void Next::execute(List<Player>& listPlayer, int playeridx, int& prize) {
    cout << "Giliran dilanjut ke player selanjutnya." << endl;
}

bool Next::continueToNextPlayer(){
    return true;
}